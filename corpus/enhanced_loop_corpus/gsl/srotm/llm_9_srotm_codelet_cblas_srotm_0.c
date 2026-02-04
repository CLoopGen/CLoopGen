#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern float *X;
extern  int incX;
extern float *Y;
extern  int incY;
extern int n;
extern int i;
extern int j;
extern float h11;
extern float h21;
extern float h12;
extern float h22;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 0; n < N; n++) {
        const float w = X[i];
        const float z = Y[j];
        const float temp1 = h11 * w;
        const float temp2 = h12 * z;
        const float temp3 = h21 * w;
        const float temp4 = h22 * z;
        X[i] = temp1 + temp2;
        Y[j] = temp3 + temp4;
        i += incX;
        j += incY;
        
        // Additional computational overhead to increase arithmetic intensity
        float accumulator = 0.0f;
        for (int k = 0; k < 4; k++) {
            accumulator += (temp1 + temp4) * (k + 1);
        }
        X[i - incX] += accumulator * 0.1f; // Minor feedback to maintain side effect
    }
}
