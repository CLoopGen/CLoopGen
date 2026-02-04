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
    int64_t local_sum = 0;
    int64_t local_sumsq = 0;
    for (y = 0; y < ydia; y++) {
        const uint8_t *srcpT = srcp + y * stride * 2;
        float *input_row = input + y * xdia;
        for (x = 0; x < xdia; x++) {
            uint32_t val = srcpT[x];
            local_sum += val;
            local_sumsq += val * val;
            input_row[x] = val;
        }
    }
    sum += local_sum;
    sumsq += local_sumsq;
}
