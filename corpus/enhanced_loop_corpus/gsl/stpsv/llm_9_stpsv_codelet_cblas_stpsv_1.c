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
if (N <= 1) return;
float sum = 0.0f;
int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX)));
for (i = 1; i < N; i++) {
    float tmp = X[ix];
    int k = 0;
    for (j = 0; j < i && k < 4; j++, k++) {
        const float Aij = Ap[(((i) * ((i) + 1)) / 2 + (j))];
        tmp -= Aij * X[jx];
        jx += incX;
    }
    while (k < i) {
        const float Aij = Ap[(((i) * ((i) + 1)) / 2 + (j))];
        tmp -= Aij * X[jx];
        jx += incX;
        j++;
        k++;
    }
    sum += tmp;
    jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX)));
}
if (nonunit && N > 1) {
    X[0] = sum / Ap[(1)]; 
}
ix = ((incX) > 0 ? 1 * incX : ((N) - 1) * (-(incX)) + incX);
}
