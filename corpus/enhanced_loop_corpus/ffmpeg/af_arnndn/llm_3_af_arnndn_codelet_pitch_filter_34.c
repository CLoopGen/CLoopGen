#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVComplexFloat {
    float re;
    float im;
} AVComplexFloat;

extern AVComplexFloat *X;
extern float normf[481];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive reverse traversal of the array from last to first
    int n = (120 << 2) + 1;
    for (int i = n - 1; i >= 0; i--) {
        X[i].re *= normf[i];
        X[i].im *= normf[i];
    }
}
