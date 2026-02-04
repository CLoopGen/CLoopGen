#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t planes[4][1024];
extern uint8_t chroma[3][256];
extern int i;
extern int j;
extern int p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 64; i += 4)
    for (j = 0; j < 16; j += 1)
        for (p = 0; p < 3; p++) {
            int idx = 32 * (i / 2) + j * 2;
            int avg = (planes[p + 1][idx] + 
                       planes[p + 1][idx + 1] + 
                       planes[p + 1][idx + 32] + 
                       planes[p + 1][idx + 33]) >> 2;
            chroma[p][(i / 4) * 8 + j] = (uint8_t)avg;
        }
}
