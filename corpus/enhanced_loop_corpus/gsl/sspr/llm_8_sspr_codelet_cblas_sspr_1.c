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
for (i = 0; i < N; i++) {
    const float tmp = alpha * X[ix];
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX)));
    for (j = 0; j <= i; j += 2) {
        Ap[(((i) * ((i) + 1)) / 2 + (j))] += X[jx] * tmp;
        if (j + 1 <= i) {
            Ap[(((i) * ((i) + 1)) / 2 + (j + 1))] += X[jx + incX] * tmp;
        }
        jx += 2 * incX;
    }
    ix += incX;
}
}
