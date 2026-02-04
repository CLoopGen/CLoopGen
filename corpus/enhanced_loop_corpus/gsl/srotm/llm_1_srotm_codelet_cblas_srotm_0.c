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
    // Introduce outer blocking loop with reduced depth but grouped iterations
    const int block_size = 4;
    int n;
    for (n = 0; n < N; n += block_size) {
        int limit = (n + block_size < N) ? n + block_size : N;
        int k;
        for (k = n; k < limit; k++) {
            const float w = X[i];
            const float z = Y[j];
            X[i] = h11 * w + h12 * z;
            Y[j] = h21 * w + h22 * z;
            i += incX;
            j += incY;
        }
    }
}
