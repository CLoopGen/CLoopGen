#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *x;
extern int maxperiod;
extern int N;
extern int i;
extern float yy;
extern float yy_lookup[769];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    // Access elements in a strided pattern instead of consecutive
    for (i = 2; i <= maxperiod; i += 2) {
        yy = yy + (x[-i] * x[-i]) - (x[N - i] * x[N - i]);
        yy_lookup[i] = ((0) > (yy) ? (0) : (yy));
        // Fill in skipped index if within bounds
        if (i - 1 <= maxperiod && i - 1 >= 1) {
            yy_lookup[i - 1] = ((0) > (yy) ? (0) : (yy));
        }
    }
    // Handle edge case for odd maxperiod
    if (maxperiod % 2 == 1) {
        yy = yy + (x[-maxperiod] * x[-maxperiod]) - (x[N - maxperiod] * x[N - maxperiod]);
        yy_lookup[maxperiod] = ((0) > (yy) ? (0) : (yy));
    }
}
