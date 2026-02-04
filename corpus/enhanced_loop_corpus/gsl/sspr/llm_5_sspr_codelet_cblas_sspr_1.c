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
    if (X[ix] == 0.0f) {
        ix += incX;
        continue;
    }
    const float tmp = alpha * X[ix];
    int jx = (incX >= 0) ? 0 : (N - 1) * (-incX);
    for (j = 0; j <= i; j++) {
        float x_val = X[jx];
        if (x_val != 0.0f) {
            Ap[(i * (i + 1)) / 2 + j] += x_val * tmp;
        }
        jx += incX;
    }
    ix += incX;
}
}
