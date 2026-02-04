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
for (i = N; i > 0 && i--;) {
    int offset_i = (i * (i + 1)) / 2;
    float atmp = Ap[offset_i + i];
    float temp = (nonunit ? X[ix] * atmp : X[ix]);
    int start_jx = (incX > 0 ? 0 : (N - 1) * (-incX));
    float *x_ptr = &X[start_jx];
    int inc_abs = (incX > 0 ? incX : -incX);
    for (j = 0; j < i; j++) {
        atmp = Ap[offset_i + j];
        temp += atmp * x_ptr[j * inc_abs];
    }
    X[ix] = temp;
    ix -= incX;
}
}
