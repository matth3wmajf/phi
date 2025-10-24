#include <phi/platform/i386-pc/ns8250.h>

/* ... */
int main() 
{
/* ... */
	phi_ns8250_com1_enable();

/* ... */
	while(1) phi_ns8250_com1_output('A');

/* ... */
	phi_ns8250_com1_disable();

/* ... */    
    return 0;
}