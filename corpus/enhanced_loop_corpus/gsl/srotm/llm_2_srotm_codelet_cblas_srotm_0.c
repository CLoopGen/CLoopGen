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
    const int idx_x = n * incX;
    const int idx_y = n * incY;
    const float w = X[idx_x];
    const float z = Y[idx_y];
    X[idx_x] = h11 * w + h12 * z;
    Y[idx_y] = h21 * w + h22 * z;
}
}
