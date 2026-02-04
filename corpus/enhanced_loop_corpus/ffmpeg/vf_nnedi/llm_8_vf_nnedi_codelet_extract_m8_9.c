#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int stride;
extern  int xdia;
extern  int ydia;
extern float *input;
extern  uint8_t *srcp;
extern int64_t sum;
extern int64_t sumsq;
extern int y;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < ydia; y++) {
    const uint8_t *srcpT = srcp + y * stride * 2;
    for (x = 0; x < xdia; x += 2) {
        if (x + 1 < xdia) {
            sum += srcpT[x] + srcpT[x+1];
            sumsq += (uint32_t)srcpT[x] * (uint32_t)srcpT[x] + 
                     (uint32_t)srcpT[x+1] * (uint32_t)srcpT[x+1];
            input[x] = srcpT[x];
            input[x+1] = srcpT[x+1];
        } else {
            sum += srcpT[x];
            sumsq += (uint32_t)srcpT[x] * (uint32_t)srcpT[x];
            input[x] = srcpT[x];
        }
    }
    input += xdia;
}
}
