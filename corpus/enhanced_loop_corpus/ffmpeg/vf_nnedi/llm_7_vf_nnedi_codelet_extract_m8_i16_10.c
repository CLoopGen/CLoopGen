#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *srcp;
extern  int stride;
extern  int xdia;
extern  int ydia;
extern int16_t *input;
extern int sum;
extern int sumsq;
extern int y;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < ydia; y++) {
        const uint8_t *srcpT = srcp + y * stride * 2;
        for (x = 0; x < xdia; x++) {
            int val = srcpT[x];
            input[x] = val;
            // Introduce artificial dependency: each iteration depends on prior sum update (WAW-like via compiler scheduling)
            // Reorder operations to change data flow: write input before updating accumulators
            sum += val;
            sumsq += val * val;
        }
        input += xdia;
    }
}
