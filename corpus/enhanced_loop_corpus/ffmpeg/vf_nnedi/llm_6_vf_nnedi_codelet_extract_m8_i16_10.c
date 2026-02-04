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
        int temp_sum = 0;
        int temp_sumsq = 0;
        for (x = 0; x < xdia; x++) {
            int val = srcpT[x];
            temp_sum += val;
            temp_sumsq += val * val;
            input[x] = val;
        }
        sum += temp_sum;
        sumsq += temp_sumsq;
        input += xdia;
    }
}
