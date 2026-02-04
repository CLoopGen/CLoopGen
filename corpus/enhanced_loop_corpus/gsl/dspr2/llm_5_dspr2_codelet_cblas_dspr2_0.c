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
extern double *Ap;
extern int i;
extern int j;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N; i++) {
        const double tmp1 = alpha * X[ix];
        const double tmp2 = alpha * Y[iy];
        int jx = ix;
        int jy = iy;
        if (tmp1 > -1e-9 && tmp1 < 1e-9) continue;
        for (j = i; j < N; j++) {
            double update = tmp1 * Y[jy];
            if (j % 2 == 0) {
                update += tmp2 * X[jx];
            }
            Ap[((((((i) - 1) + 1) * (2 * (N) - ((i) - 1))) / 2) + (j) - (i))] += update;
            jx += incX;
            jy += incY;
        }
        ix += incX;
        iy += incY;
    }
}
