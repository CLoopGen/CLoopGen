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
    X[i] = h11 * w + h12 * z;
    Y[j] = h21 * w + h22 * z;
    i += incX;
    j += incY;
}

}
