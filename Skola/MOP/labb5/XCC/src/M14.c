#define	ML4IN	0x0600
#define ML4OUT	0x0400

#include <Appstart.s12>

#define	ML4READ	* ((char*)ML4IN)
#define	ML4WRITE * ((char*)ML4OUT)


void main(void){

	char c;
	while(1){
		c = ML4READ;
		if(c == 64)
			exit();
		c = c << 1;
		ML4WRITE = c;
	}
}