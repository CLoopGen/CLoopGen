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
    int jx = 0;
    int jy = 0;
    // Force unit-stride access by precomputing base pointers and using consecutive indexing
    float *baseX = &X[(incX > 0 ? 0 : (N - 1) * (-incX))];
    float *baseY = &Y[(incY > 0 ? 0 : (N - 1) * (-incY))];
    for (j = 0; j <= i; j++) {
        Ap[(i * (i + 1)) / 2 + j] += tmp1 * baseY[jy] + tmp2 * baseX[jx];
        jx += 1; // now accessing X with unit stride via remapped base
        jy += 1; // same for Y
    }
    ix += incX;
    iy += incY;
}
}
