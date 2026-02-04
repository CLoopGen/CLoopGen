#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVComplexFloat {
    float re;
    float im;
} AVComplexFloat;

extern AVComplexFloat *X;
extern  AVComplexFloat *P;
extern float rf[481];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Unroll the loop into a single deeper nested structure with reduced iterations
    int n = ((120 << 2) + 1);
    for (int i = 0; i < n; i += 4) {
        for (int step = 0; step < 4 && (i + step) < n; step++) {
            int idx = i + step;
            X[idx].re += rf[idx] * P[idx].re;
            X[idx].im += rf[idx] * P[idx].im;
        }
    }
}
