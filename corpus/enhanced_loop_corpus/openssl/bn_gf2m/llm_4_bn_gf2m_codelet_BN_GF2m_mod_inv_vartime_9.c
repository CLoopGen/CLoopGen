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
    if (vdp[i] != 0) {
        udp[i] ^= vdp[i];
    }
    if (cdp[i] != 0) {
        bdp[i] ^= cdp[i];
    }
}
}
