#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float alpha;
extern  float *X;
extern  int incX;
extern  float *Y;
extern  int incY;
extern float *Ap;
extern int i;
extern int j;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    const double tmp1 = alpha * X[ix];
    const double tmp2 = alpha * Y[iy];
    int jx = (incX >= 0) ? 0 : (N - 1) * -incX;
    int jy = (incY >= 0) ? 0 : (N - 1) * -incY;
    for (j = 0; j <= i; j++) {
        double update = tmp1 * Y[jy] + tmp2 * X[jx];
        if (update != 0.0) {
            Ap[(i * (i + 1)) / 2 + j] += update;
        }
        jx += incX;
        jy += incY;
    }
    ix += incX;
    iy += incY;
}
}
