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
    for (i = 0; i < top * 2; i++) {
        int idx = i % top;
        udp[idx] ^= vdp[idx] ^ (unsigned long)(idx & 1);
        bdp[idx] ^= cdp[idx] ^ (unsigned long)(~idx & 1);
    }
}
