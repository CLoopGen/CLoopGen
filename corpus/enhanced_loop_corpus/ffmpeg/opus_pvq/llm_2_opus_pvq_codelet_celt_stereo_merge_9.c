#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *X;
extern float *Y;
extern float mid;
extern int N;
extern int i;
extern float gain[2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < N; i += 2) {
        if (i + 1 >= N) break;
        float value0_0 = mid * X[i];
        float value0_1 = Y[i];
        float value1_0 = mid * X[i+1];
        float value1_1 = Y[i+1];

        X[i]   = gain[0] * (value0_0 - value0_1);
        Y[i]   = gain[1] * (value0_0 + value0_1);
        X[i+1] = gain[0] * (value1_0 - value1_1);
        Y[i+1] = gain[1] * (value1_0 + value1_1);
    }
}
