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
    for (x = 0; x < xdia; x++) {
        uint8_t val = srcpT[x];
        if (val > 0) {
            sum += val;
            sumsq += (uint32_t)val * val;
            input[x] = val;
        } else {
            input[x] = 0;
        }
    }
    input += xdia;
}
}
