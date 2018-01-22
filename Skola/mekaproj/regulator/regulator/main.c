#include <xc.h>
#include "lcd.h"
#include <stdlib.h>

//Configuration Bits---------------------------------------------------------
#pragma config FOSC=XT, FCMEN=OFF //Extern Oscillator, FailSafe disabled
#pragma config HFOFST=OFF //Delay until fosc stable
#pragma config PLLCFG=OFF, IESO=OFF //PLL Off, Osc switchover disabled
#pragma config PRICLKEN=ON //Primary clock enabled
#pragma config PWRTEN=ON, BOREN=OFF //Power-Up timer enabled, BOR off
#pragma config MCLRE=EXTMCLR, XINST=OFF//MCLR extern, I-set extension disabled
#pragma config WDTEN=OFF, LVP=OFF //Watchdog timer & Low Volt prog disabled
#pragma config DEBUG=OFF, STVREN=ON //Stack Full/Underflow will cause Reset

#define _XTAL_FREQ 4000000

void init (void);
void interrupt isr (void);
unsigned char hr=0, min=0, sec=0, tiondel=0;
unsigned int ADC_LB, ADC_HB;
unsigned int PWM_HB = 0, PWM_LB = 0, duty_cycle;
char channel;
char raknare = 0;
float gammal_pwmut;
float gammal_fel;
float pwmut;
float fel = 0;
void show_values(unsigned int SP, unsigned int PV); // ärvärde o börvärde
void show_clock();              // Visar klocka
void LOW_BATTERY();             //
void PWM_OUT(unsigned int duty_cycle);
unsigned int ADC_10bit(char channel);
void UART_INIT();


void main(void)
{   init();
    lcd_init();
    UART_INIT();

    int count = 0;
 //   float fel = 0;
//    float gammal_fel;
  //  unsigned int K = 10;
    //float pwmut;
//    float gammal_pwmut;
    unsigned int SP;
    unsigned int PV;
    float ar_varde;
    float bor_varde;
    float bv = 0;
  //  char raknare = 0;

    while(1){

         ar_varde = ADC_10bit(4);
         bor_varde = ADC_10bit(0);

        if(PORTCbits.RC2){ // rampfunktion PÅ
            SP = bor_varde * (99./1023);
            PV = ar_varde * (99./1023);

            fel = bv - (ar_varde);

            if((bv/1)!=(bor_varde/1)){
               lcd_goto(0x00);
               lcd_writesc("RAMPAR");
            }

            if(count < 4){
                count++;        // delay
            }

            if((count == 4) && (bv < bor_varde)){
                bv += 10;
                if(bv > 1023){
                    bv = 1023;   // begränsar
                }
                count = 0;
            }
            else if (bv==bor_varde){
                lcd_goto(0x00);
                lcd_writesc("      ");
            }

            else if((count == 4) && (bv > bor_varde)){
                bv -= 10;
                if(bv < 0){
                    bv = 0;      // // begränsar
                }
                count = 0;

            }
    
        }

        if(!PORTCbits.RC2){
            lcd_goto(0x00);
            lcd_writesc("      ");      // rensar texten "rampar"
            SP = bor_varde * (99./1023);
            PV = ar_varde * (99./1023);
            fel = bor_varde  - (ar_varde) ;
            bv = ar_varde;
        }
        int b = (ADC_10bit(4)>>2)*99./255;
        TXREG1 = b;
        show_values(SP,PV);         // visar bor o arvarde
        show_clock();               // visar klocka
        LOW_BATTERY();
        // y(k) = 5.945*r(k)+3.547*r(k-1)- y(k-1)

        pwmut = (4.820924223288709*fel) - (4.671075776711291*gammal_fel) + gammal_pwmut;

        if(pwmut >= 1023.00){
            pwmut = 1023.00;

        }
        if(pwmut <= 0.00){
            pwmut = 0.00;

        }


       PWM_OUT(pwmut);         // send ad as PWM signal
       gammal_fel = fel;
       gammal_pwmut = pwmut;
       
        __delay_ms(100);
        __delay_ms(100);
        __delay_ms(100);
        __delay_ms(100);
        __delay_ms(89);        


        if(PORTAbits.RA1 == 1){
            hr++;
            if(hr == 24){
               hr = 0;
            }
            while(PORTAbits.RA1 == 1);
        }
        else if(PORTAbits.RA2 == 1){
            min++;
            if(min == 60){
                min = 0;
            }
            while(PORTAbits.RA2 == 1);
        }
        else if(PORTAbits.RA3 == 1){
            sec = 0;
            while(PORTAbits.RA3 == 1);
        }
        
    }
    
}
void init(void)
{
    ANSELA = 0b00100001;    /// AN0 analog
    ANSELB = 0b00001000;    // RB3 analog resten digital
    ANSELC = 0; //PortB alla digitala
    //AD omvandling
    TRISAbits.RA0 = 1;      // RA0 input
    TRISAbits.RA1 = 1;      // RA1 input
    TRISAbits.RA2 = 1;      // RA2 input
    TRISAbits.RA3 = 1;      // RA3 input
    TRISAbits.RA4 = 0;      // RA4 output PWM
    TRISAbits.RA5 = 1;      // RA5 input
    TRISCbits.RC3 = 0;      //Port C3 utgång
    TRISBbits.RB3 = 1;      //Port B3 Ingång
    //TRISBbits.RB4 = 0;      //Port B4 utgång
    TRISB=0b00001000;

    
    /////////
    ADCON2 = 0b10001010;    // right justified( set bit 7), 2*Tacq,
                            // bit 5 - 3 = 010 charging time Chold
                            // when 8uS
    ADCON1 = 0x00;
    ADCON0 = 0x01;


    T1CON=0b00010001; //Enable TMR1,8-bit r/w,Fosc/4 source,Prescale=2
    TMR1H=60; //Ställer TMR1 så att delay=0.1 sekund
    TMR1L=237;
    ///////// PWM //////////////
    CCPTMRS1 = 0x01;    // selecting timer2 to be used
                        // for PWM generation
    PR2 = 255;          // pulse lenght
    CCP5CON = 0x0C;     // PWM-mode
    T2CON = 0x04;       // Enable timer2 and prescaler = 1
///////////////komparator - LOW BATTERY////////
    CM1CON0bits.C1CH = 0b10;    // RB3
    CM1CON0bits.C1R = 1;        // CxVIN+ connects to CXVREF output
    CM1CON0bits.C1OE = 0;
    CM1CON0bits.C1ON = 1;
    CM1CON0bits.C1POL = 0;      // When CxVIN+ > CxVIN- non-inverted
    CM1CON0bits.C1SP = 0;       // ??

    CM2CON1bits.C1RSEL = 1;     // FVR BUF1 as ref voltage
    //CM1CON0bits.C1OUT = 1;      // When CxVIN+ > CxVIN-
    VREFCON0bits.FVREN = 1;     // Fixed Voltage Reference is enabled
    
    VREFCON0bits.FVRS = 0b11;   // 11 = Fixed Voltage Reference
                                // Peripheral output is 4x (4.096V)(1)

    //Initiera interrupt
    PIE1=0b00000001; //TMR1 interrupt enable
    IPR1=0b00000001; //TMR1 interrupt High Priority
    INTCON=0b11000000; //Global/Peripheral interrupt enable
}

//High Priority Interrupt service routine--------------------------------------
void interrupt isr(void)
{
    if(PIR1bits.TMR1IF && PIE1bits.TMR1IE) //Vilken interrupt aktuell
    {

        TMR1H=60; //Återställer TMR1
        TMR1L=237;


        if(++tiondel>=10) //Räkna upp tiondelssekunder
        {   tiondel=0;
            if(++sec>=60) //Räkna upp sekunder
            { sec=0;
                if(++min>=60) //Räkna upp minuter
                {   min=0;
                    if(++hr>=24) //Räkna upp timmar
                    hr=0;
                }
            }
        }
        PIR1bits.TMR1IF = 0; //Nollställer interruptflagga
    }
}
unsigned int ADC_10bit(char channel){
    ADCON0 = (ADCON0 & 0b10000011)|(channel<<2);    //selecting channel
    __delay_us(8);                                  //delay 8us
    ADCON0bits.GO = 1;                              //start conversion
    while(ADCON0bits.GO);                           //wait for ADC convertion
                                                    //to complete
    ADC_HB = ADRESH;                                // save high bit and low bit
    ADC_LB = ADRESL;                                //
    return (ADC_HB<<8|ADC_LB);

}
void PWM_OUT(unsigned int duty_cycle){
    // PWM RA4
    PWM_HB = duty_cycle>>2;                 // 8 MSB
    PWM_LB = duty_cycle & 0x0003;           // 2 LSB
    CCPR5L = PWM_HB;                        // 8 MSB to CCPR5L register
    CCP5CON = (CCP5CON & 0b11001111)|(PWM_LB<<4); // OR and AND-shift registers
}

void show_values(unsigned int SP, unsigned int PV){

    unsigned int SP1 = SP;
    unsigned int PV1 = PV;


    lcd_goto(0x0A);
    lcd_write('S');
    lcd_write('P');
    lcd_write(':');
    lcd_write('0'+SP1/10);
    lcd_write('0'+SP1%10);
    lcd_write('%');

    lcd_goto(0x4A);
    lcd_writesc("PV:");
    lcd_write('0'+PV1/10);
    lcd_write('0'+PV1%10);
    lcd_write('%');

}

void show_clock(){

        lcd_goto(0x40);
        lcd_write('0'+hr/10);
        lcd_write('0'+hr%10);
        lcd_write(':');
        lcd_write('0'+min/10);
        lcd_write('0'+min%10);
        lcd_write(':');
        lcd_write('0'+sec/10);
        lcd_write('0'+sec%10);

}

void LOW_BATTERY(){

          if(CM1CON0bits.C1OUT){

          lcd_goto(0x40);
          lcd_writesc("Low battery     ");
          char delayy = 10;
          if(delayy){
              __delay_ms(100);
              delayy--;
          }
          lcd_goto(0x40);
          lcd_writesc("                ");
          char delayy = 10;
          if(delayy){
              __delay_ms(100);
              delayy--;
          }

        }
}

void UART_INIT(){

    TRISCbits.TRISC6 = 1; //TX1 input
    TRISCbits.TRISC7 = 1; //RX1 input måste ändras
    ANSELCbits.ANSC6 = 0; //RX1 input is digital
    ANSELCbits.ANSC7 = 0;
    SPBRG1 = 12;        //EUSART1 Baud Rate Generator, Low Byte
    SPBRGH1 = 0;        //EUSART1 Baud Rate Generator, High Byte
                        // see table at page 283 @ 19.2k and 4MHz
    //SYNC = 0, BRGH = 0, BRG16 = 1
    BAUDCON1bits.BRG16 = 1; // 16-bit Baud Rate Generator is
                            // used (SPBRGHx:SPBRGx)
    TXSTAbits.BRGH = 0; // Low baud rate mode
    TXSTAbits.SYNC = 0; // Asynchronous
    TXSTAbits.TXEN = 1; // enable transmitter
    RCSTAbits.SPEN = 1; //Serial port enabled (configures RXx/DTx
                        //and TXx/CKx pins as serial port pins
}