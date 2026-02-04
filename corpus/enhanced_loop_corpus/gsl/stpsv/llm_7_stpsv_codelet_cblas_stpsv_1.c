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
float *temp_array = (float*)malloc(N * sizeof(float));
if (temp_array == NULL) return;
for (i = 1; i < N; i++) {
    float tmp = X[i * incX];
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX)));
    for (j = 0; j < i; j++) {
        const float Aij = Ap[(((i) * ((i) + 1)) / 2 + (j))];
        tmp -= Aij * X[jx];
        jx += incX;
    }
    temp_array[i] = tmp;
}
for (i = 1; i < N; i++) {
    int idx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + i * incX;
    if (nonunit) {
        X[idx] = temp_array[i] / Ap[(((i) * ((i) + 1)) / 2 + (i))];
    } else {
        X[idx] = temp_array[i];
    }
}
free(temp_array);
}
