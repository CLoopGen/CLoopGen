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
    int local_sum = 0;
    int local_sumsq = 0;
    for (x = 0; x < xdia; x += 4) {
        for (int k = 0; k < 4 && (x + k) < xdia; k++) {
            uint8_t val = srcpT[x + k];
            local_sum += val;
            local_sumsq += val * val;
            input[x + k] = val;
        }
    }
    sum += local_sum;
    sumsq += local_sumsq;
    input += xdia;
}
}
