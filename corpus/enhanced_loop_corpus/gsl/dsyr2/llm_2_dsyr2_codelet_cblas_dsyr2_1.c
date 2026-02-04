#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double alpha;
extern  double *X;
extern  int incX;
extern  double *Y;
extern  int incY;
extern double *A;
extern  int lda;
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
    // Adjust starting index based on stride direction for consecutive logical access
    if (incX < 0) jx = -(incX) * (N - 1);
    if (incY < 0) jy = -(incY) * (N - 1);
    for (j = 0; j <= i; j++) {
        // Access A in row-major but modify X and Y to use increasing strides uniformly
        A[lda * i + j] += tmp1 * Y[jy] + tmp2 * X[jx];
        jx += incX;
        jy += incY;
    }
    ix += incX;
    iy += incY;
}
}
