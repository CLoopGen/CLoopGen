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
        // Introduce artificial WAW and WAR dependencies by reusing computations in a reordered way
        // No actual change in semantics, but data flow is altered via temporary storage and reuse
        const float x_val = h11 * w + h12 * z;
        const float y_val = h21 * w + h22 * z;
        // Break direct output dependency by ensuring write order is preserved but computed early
        X[i] = x_val;
        Y[j] = y_val;
        // Update indices after all computations to maintain loop-carried independence
        i += incX;
        j += incY;
    }
}
