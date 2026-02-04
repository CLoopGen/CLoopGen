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
        sum += srcpT[x * 2]; 
        sumsq += (uint32_t)srcpT[x * 2] * (uint32_t)srcpT[x * 2];
        input[x] = srcpT[x * 2];
    }
    input += xdia;
}
}
