#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float *X;
extern  int incX;
extern  float *Y;
extern  int incY;
extern float r;
extern int i;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int *indices = (int*)alloca(N * sizeof(int));
for (int j = 0; j < N; j++) {
    indices[j] = j;
}
for (i = 0; i < N; i++) {
    int idx = indices[i];
    r += X[ix + idx] * Y[iy + idx];
}
}
