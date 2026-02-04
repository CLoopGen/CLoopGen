#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int top;
extern unsigned long *udp;
extern unsigned long *bdp;
extern unsigned long *vdp;
extern unsigned long *cdp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < top; i++) {
        unsigned long temp = vdp[i];
        udp[i] ^= temp;
        temp = cdp[i];
        bdp[i] ^= temp;
    }
}
