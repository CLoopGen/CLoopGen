#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dest;
extern int linesize;
extern int i;
extern int temp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access with Pointer Arithmetic
    uint8_t *d = dest;
    int offset = 0;
    for (i = 0; i < 8; i++) {
        int *t = &temp[8 * i];
        const int a0 = t[0] + t[4];
        const int a1 = t[0] - t[4];
        const int a2 = t[2] + t[6];
        const int a3 = ((int)((unsigned int)(2896) * (t[2] - t[6])) >> 11);
        const int a4 = t[5] + t[3];
        const int a5 = t[5] - t[3];
        const int a6 = t[1] + t[7];
        const int a7 = t[1] - t[7];
        const int b0 = a4 + a6;
        const int b1 = ((int)((unsigned int)(3784) * (a5 + a7)) >> 11);
        const int b2 = ((int)((unsigned int)(-5352) * a5) >> 11) - b0 + b1;
        const int b3 = ((int)((unsigned int)(2896) * (a6 - a4)) >> 11) - b2;
        const int b4 = ((int)((unsigned int)(2217) * a7) >> 11) + b3 - b1;
        
        // Write output using consecutive pointer increments
        d[offset + 0] = ((a0 + a2 + b0) + 127) >> 8;
        d[offset + 1] = ((a1 + a3 - a2 + b2) + 127) >> 8;
        d[offset + 2] = ((a1 - a3 + a2 + b3) + 127) >> 8;
        d[offset + 3] = ((a0 - a2 - b4) + 127) >> 8;
        d[offset + 4] = ((a0 - a2 + b4) + 127) >> 8;
        d[offset + 5] = ((a1 - a3 + a2 - b3) + 127) >> 8;
        d[offset + 6] = ((a1 + a3 - a2 - b2) + 127) >> 8;
        d[offset + 7] = ((a0 + a2 - b0) + 127) >> 8;
        
        offset += linesize;
    }
}
