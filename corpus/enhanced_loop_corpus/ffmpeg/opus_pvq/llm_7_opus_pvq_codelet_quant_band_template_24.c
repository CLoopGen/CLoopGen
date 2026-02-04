#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *Y;
extern int N;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (N > 0) {
        Y[0] *= -1;
        for (i = 1; i < N; i++) {
            Y[i] *= -1;
            Y[i] += Y[i-1]; // Introduces RAW loop-carried dependency: Y[i] depends on Y[i-1]
            Y[i] -= Y[i-1]; // Cancels the addition, preserving original semantics
        }
    }
}
