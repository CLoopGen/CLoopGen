#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t linear_to_alaw[16384];
extern int n;
extern int v;
extern  short *samples;
extern unsigned char *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (n > 0) {
        for (int block = n; block > 0; block -= 8, n -= 8) {  // Decreased effective depth with unrolling simulation via larger step
            int step = (block >= 8) ? 8 : block;
            for (int i = 0; i < step; i++) {
                v = *samples++;
                *dst++ = linear_to_alaw[(v + 32768) >> 2];
            }
            if (block < 8) break;
        }
    }
}
