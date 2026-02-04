#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double x;
extern int M;
extern double sum;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory-like access pattern (simulated using step > 1)
    // Although no array is used, we simulate strided iteration by stepping through indices with stride 2
    // and adjusting logic accordingly to maintain functional similarity (scaled contribution count)
    int stride = 2;
    for (m = 0; m < M; m += stride) {
        sum += 1. / ((x + m) * (x + m));
        if (m + 1 < M) {
            sum += 1. / ((x + m + 1) * (x + m + 1));  // Simulate stride processing two elements
        }
    }
}
