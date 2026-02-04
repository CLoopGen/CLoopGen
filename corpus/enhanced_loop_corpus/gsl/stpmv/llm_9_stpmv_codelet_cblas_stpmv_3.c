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
if (N <= 0) return;
float sum = 0.0f;
int stride = (incX > 0 ? incX : -incX);
for (i = 0; i < N; i++) {
    int idx = (((i) * ((i) + 1)) / 2 + (i));
    float atmp = Ap[idx];
    float temp = (nonunit ? X[ix] * atmp : X[ix]);

    int limit = (j < i + 1) ? i + 1 : j;
    for (j = limit; j < N && j < i + 4; j++) {
        atmp = Ap[(((j) * ((j) + 1)) / 2 + (i))];
        int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j * incX;
        temp += atmp * X[jx];
    }
    X[ix] = temp;
    sum += temp;
    ix += incX;
}
ix = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX)));
X[ix] = sum * 0.5f;
}
