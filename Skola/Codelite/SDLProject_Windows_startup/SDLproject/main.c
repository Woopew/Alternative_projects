#include "renderer.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//int pos_x = 400, pos_y = 300;
/*
typedef volatile int* port32ptr;

#define INUTPORT_ADDR_X &pos_x
#define INUTPORT_X *((port32ptr)INUTPORT_ADDR_X)

#define INUTPORT_ADDR_Y &pos_y
#define INUTPORT_Y *((port32ptr)INUTPORT_ADDR_Y)
*/

GfxObject ship, background;

int t = 0;
bool bShake = false;
int shakeStop = 0;

void shake_pos(int *x,int *y);
void close();
void reverse(char *str);

int main( int argc, char* args[] )
{
    // If you want the program to not launch the terminal, then go to 
    // Project->Settings->General->"This program is a GUI application" and uncheck that flag.
    
	// Start up SDL and create window of width=800, height = 600
	initRenderer(800, 600); 
    
	// Reverting string basis
	char rev[] = "PariS";
	
	// Create backround behind ship
	background = createGfxObject( "../background.jpg" );
	background.outputHeight = 600;
	background.outputWidth = 800;
	double angle = 0;
	double shipAngle = 0, shipAngleSpeed = 90.0/360.0;
	float scale = 1.8f, scaleSpeed = 1.0/100.0;
	int pos_x = 400, pos_y = 300, loopIter=0, speed = 5;

	
    // Create an object
    ship = createGfxObject(  "../ship2.png" );
    ship.outputWidth  = 200;
    ship.outputHeight = 200;
	
	// get pointer to key states
    const Uint8 *state = SDL_GetKeyboardState(NULL);
	
    while(true) // The real-time loop
    {
        // Handle events on the inqueue (e.g., mouse events)
        SDL_Event e;  //Event handler
        while( SDL_PollEvent( &e ) != 0 )
        {
            if( e.type == SDL_QUIT ) {   //User requests quit
                close(); 
                exit(0);
            }
        }
        
        // Clear screen with a grey background color, red=0x33, blue=0x33, green=0x33, alpha=0xff. 0=minimum, 0xff=maximum.
        // Alpha is transparency: 0 = fully transparent, 0xFF = fully opaque. However, actual use of transparency requires further settings.
        SDL_SetRenderDrawColor( gRenderer, 0x33, 0x33, 0x33, 0xFF ); 
        SDL_RenderClear( gRenderer );
/*
		if (state[SDL_SCANCODE_RIGHT])
            // Right-Arrow key is pressed.
			pos_x += 2;
		if (state[SDL_SCANCODE_LEFT])
            // Right-Arrow key is pressed.
			pos_x -= 2;
		if (state[SDL_SCANCODE_UP])
            // Right-Arrow key is pressed.
				pos_y -= 2;
		if (state[SDL_SCANCODE_DOWN]) 
            // Right-Arrow key is pressed.
				pos_y += 2;
*/
        if (state[SDL_SCANCODE_RIGHT])
            pos_x = (pos_x+speed >= 799) ? 799 : pos_x+speed;
        if (state[SDL_SCANCODE_LEFT])
            pos_x = (pos_x-speed <= 0) ? 0 : pos_x-speed; 
        if (state[SDL_SCANCODE_DOWN])
            pos_y = (pos_y+speed >= 599) ? 599 : pos_y+speed;           
        if (state[SDL_SCANCODE_UP])
            pos_y = (pos_y-speed <= 0) ? 0 : pos_y-speed;
			
		if (state[SDL_SCANCODE_SPACE])
			shipAngle = fmod(shipAngle+10, 360);
		if (state[SDL_SCANCODE_W])
            scale = scale + scaleSpeed;           
        if (state[SDL_SCANCODE_S])
            scale = (scale - scaleSpeed <= 0) ? 0 : scale-scaleSpeed;            
        if (state[SDL_SCANCODE_A])
            shipAngle = fmod(shipAngle - shipAngleSpeed, 360.0);           
        if (state[SDL_SCANCODE_D])
            shipAngle = fmod(shipAngle + shipAngleSpeed, 360.0);
			
        // Render our object(s) - background objects first, and then forward objects (like a painter)
		angle = fmod(angle+0.02, 360);
		scale += 1.0/2500.0;
        renderGfxObject(&background, 400, 300, angle, scale);
		renderGfxObject(&ship, pos_x, pos_y, shipAngle, 1.0f);
        renderText("Do a barrel roll!", 300, 150);
		
		if((loopIter % 200) == 99){
			reverse(rev);
		
		
		}
		//reversing string
			renderText(rev,0,100);
		//shake the ship a bit 
		shake_pos(&pos_x, &pos_y);
         //renderGfxObject(&ship, pos_x, pos_y, shipAngle, 1.0f);
        // This function updates the screen and also sleeps ~16 ms or so (based on the screen's refresh rate),  
        // because we used the flag SDL_RENDERER_PRESENTVSYNC in function initRenderer()
        SDL_RenderPresent( gRenderer );
		loopIter++;
    }

	close(); //Free allocated resources
	return 0;
}

void close(){
    //Preferably, you should free all your GfxObjects, by calls to freeGfxObject(GfxObject* obj), but you don't have to.
    freeGfxObject(&ship);
	freeGfxObject(&background);
    closeRenderer(); //Free resources and close SDL
}
void shake_pos(int *x,int *y){
	if( bShake == false && ((rand() % 60)==1) ) {
		bShake = true;
		shakeStop = t + (rand() % 20) + 30;
    }
    if( bShake && t < shakeStop) {
		renderText("Shaking!", 0, 0);
		*x += 2 * ((t % 3) - 1);
		*y += 2 * ((rand() % 3) - 1); 
    }
    if( bShake && (t >= shakeStop) ) {
        bShake = false;
    }
    t++;
}
void reverse(char str[]){
	//
	int l = strlen(str);
	printf("%d\n", l);
	int half_len = l/2;
	printf("%d\n", half_len);
	printf("%s\n",str);
	//Ye old switcharoo!
	for(int i = 0; i < half_len; i++){
		char t = str[i];
		str[i] = str[l-i-1];
		str[l-i-1] = t; 
		printf("%s\n",str);
	}
}

//char rev[] = "ParisA";