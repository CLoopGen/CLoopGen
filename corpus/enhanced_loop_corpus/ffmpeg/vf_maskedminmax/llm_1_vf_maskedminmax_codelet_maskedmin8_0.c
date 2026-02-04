#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern  uint8_t *f1;
extern  uint8_t *f2;
extern int w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int y = 0; y < w; y++) {
        for (int x = y; x <= y; x++) {  // Artificially nested with fixed inner iteration
            dst[x] = ((src[x] - f2[x]) >= 0 ? (src[x] - f2[x]) : (-(src[x] - f2[x]))) < ((src[x] - f1[x]) >= 0 ? (src[x] - f1[x]) : (-(src[x] - f1[x]))) ? f2[x] : f1[x];
        }
    }
}
