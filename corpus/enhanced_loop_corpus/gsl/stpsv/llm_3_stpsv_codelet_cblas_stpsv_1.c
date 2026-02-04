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
for (i = 1; i < N; i++) {
    float tmp = X[ix];
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX)));
    int a_offset = (i * (i + 1)) / 2;
    float *Ap_ptr = &Ap[a_offset];
    float *X_ptr = X;
    for (j = 0; j < i; j++) {
        tmp -= Ap_ptr[j] * X_ptr[jx];
        jx += incX;
    }
    if (nonunit) {
        X[ix] = tmp / Ap_ptr[j];
    } else {
        X[ix] = tmp;
    }
    ix += incX;
}
}
