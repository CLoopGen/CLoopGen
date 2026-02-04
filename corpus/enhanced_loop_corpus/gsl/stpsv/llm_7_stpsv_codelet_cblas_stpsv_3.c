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
float *temp_cache = (float*)alloca(N * sizeof(float));
for (int k = 0; k < N; k++) {
    temp_cache[k] = X[k * incX]; 
}
for (i = N - 1; i >= 0; i--) {
    float tmp = temp_cache[i];
    for (j = i + 1; j < N; j++) {
        const float Aji = Ap[(((j) * ((j) + 1)) / 2 + (i))];
        tmp -= Aji * temp_cache[j];
    }
    if (nonunit) {
        temp_cache[i] = tmp / Ap[(((i) * ((i) + 1)) / 2 + (i))];
    } else {
        temp_cache[i] = tmp;
    }
}
for (i = N - 1, j = 0; j < N; i--, j++) {
    X[i * incX] = temp_cache[j];
}
}
