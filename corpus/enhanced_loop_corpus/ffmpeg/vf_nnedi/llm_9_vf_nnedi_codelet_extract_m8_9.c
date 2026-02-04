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
for (y = 0; y < ydia; y += 2) {
    if (y + 1 >= ydia) {
        const uint8_t *srcpT = srcp + y * stride * 2;
        for (x = 0; x < xdia; x++) {
            sum += srcpT[x];
            sumsq += (uint32_t)srcpT[x] * (uint32_t)srcpT[x];
            input[x] = srcpT[x];
        }
        input += xdia;
    } else {
        const uint8_t *srcpT1 = srcp + y * stride * 2;
        const uint8_t *srcpT2 = srcp + (y + 1) * stride * 2;
        for (x = 0; x < xdia; x++) {
            sum += srcpT1[x] + srcpT2[x];
            sumsq += (uint32_t)srcpT1[x] * (uint32_t)srcpT1[x] + 
                     (uint32_t)srcpT2[x] * (uint32_t)srcpT2[x];
            input[x] = srcpT1[x];
            input[xdia + x] = srcpT2[x];
        }
        input += 2 * xdia;
    }
}
}
