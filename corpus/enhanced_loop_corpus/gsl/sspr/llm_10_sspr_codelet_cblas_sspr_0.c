#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float alpha;
extern  float *X;
extern  int incX;
extern float *Ap;
extern int i;
extern int j;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (N <= 0) return;
const float tmp = alpha * X[ix];
int jx = ix;
for (j = 0; j < N; j++) {
    Ap[(j * (2 * N - j)) / 2] += X[jx] * tmp;
    jx += incX;
}
ix += incX;
for (i = 1; i < N; i++) {
    const float tmp = alpha * X[ix];
    int jx = ix;
    for (j = i; j < N; j += 2) {
        int idx = (((i) * (2 * N - i)) / 2) + (j - i);
        Ap[idx] += X[jx] * tmp;
        if (j + 1 < N) {
            Ap[idx + 1] += X[jx + incX] * tmp;
        }
        jx += 2 * incX;
    }
    ix += incX;
}
}
