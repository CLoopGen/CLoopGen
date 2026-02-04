#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *myu;
extern double *omega;
extern double *probability;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in reverse order, then handle remainder)
    // This changes the pattern to non-consecutive and introduces a stride of 2
    for (i = 254; i >= 1; i -= 2) {
        omega[i] = omega[i - 1] + probability[i];
        myu[i] = myu[i - 1] + i * probability[i];
    }
    for (i = 255; i >= 1; i -= 2) {
        omega[i] = omega[i - 1] + probability[i];
        myu[i] = myu[i - 1] + i * probability[i];
    }
}
