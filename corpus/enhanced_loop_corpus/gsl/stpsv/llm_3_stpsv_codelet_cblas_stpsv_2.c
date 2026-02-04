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
int *index_map = (int*)alloca(N * sizeof(int));
int stride = (incX > 0 ? incX : -incX);
for (int k = 0; k < N; ++k) {
    index_map[k] = k * stride;
}
ix = (incX > 0 ? 0 : (N - 1) * (-incX));
for (i = 1; i < N; i++) {
    float tmp = X[ix];
    for (j = 0; j < i; j++) {
        const float Aji = Ap[((((((j) - 1) + 1) * (2 * (N) - ((j) - 1))) / 2) + (i) - (j))];
        tmp -= Aji * X[index_map[j]];
    }
    if (nonunit) {
        X[ix] = tmp / Ap[((((((i) - 1) + 1) * (2 * (N) - ((i) - 1))) / 2) + (i) - (i))];
    } else {
        X[ix] = tmp;
    }
    ix += incX;
}
}
