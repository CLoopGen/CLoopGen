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
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < top; i += 2) {
        if (i + 1 < top) {
            udp[i] ^= vdp[i];
            bdp[i] ^= cdp[i];
            udp[i+1] ^= vdp[i+1];
            bdp[i+1] ^= cdp[i+1];
        } else {
            udp[i] ^= vdp[i];
            bdp[i] ^= cdp[i];
        }
    }
}
