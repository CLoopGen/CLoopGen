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
float *Ap_local = Ap;
float *X_local = X;
int ix_local = ix;
for (i = 0; i < N; i++) {
    int row_start = (i * (2 * N - i + 1)) / 2;
    float diag_val = Ap_local[row_start];
    float temp = (nonunit ? X_local[ix_local] * diag_val : X_local[ix_local]);
    int jx = ix_local + incX;
    for (j = i + 1; j < N; j++) {
        float a_val = Ap_local[row_start + (j - i)];
        temp += a_val * X_local[jx];
        jx += incX;
    }
    X_local[ix_local] = temp;
    ix_local += incX;
}
ix = ix_local;
}
