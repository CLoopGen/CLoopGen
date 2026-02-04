#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float *Ap;
extern float *X;
extern  int incX;
extern int i;
extern int j;
extern  int nonunit;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int stride = (incX > 0 ? incX : -incX);
for (i = 0; i < N; i += 2) {
    int ix1 = ix;
    int ix2 = ix + stride;
    float temp1 = X[ix1];
    float temp2 = X[ix2];
    if (nonunit) {
        float a11 = Ap[((((((i) - 1) + 1) * (2 * (N) - ((i) - 1))) / 2) + (i) - (i))];
        float a22 = Ap[((((((i+1) - 1) + 1) * (2 * (N) - ((i+1) - 1))) / 2) + (i+1) - (i+1))];
        temp1 *= a11;
        temp2 *= a22;
    }
    for (j = i + 1; j < N; j++) {
        float a1j = Ap[((((((i) - 1) + 1) * (2 * (N) - ((i) - 1))) / 2) + (j) - (i))];
        float a2j = Ap[((((((i+1) - 1) + 1) * (2 * (N) - ((i+1) - 1))) / 2) + (j) - (i+1))];
        int jx = ((incX) > 0 ? 0 : (N - 1) * (-incX)) + j * incX;
        temp1 += a1j * X[jx];
        temp2 += a2j * X[jx];
    }
    X[ix1] = temp1;
    if (i + 1 < N) X[ix2] = temp2;
    ix += 2 * incX;
}
}
