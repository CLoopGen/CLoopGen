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
    for (i = 1; i < top; i++) {
        udp[i] ^= vdp[i-1];
        bdp[i] ^= cdp[i-1];
    }
    if (top > 0) {
        udp[0] ^= vdp[0];
        bdp[0] ^= cdp[0];
    }
}
