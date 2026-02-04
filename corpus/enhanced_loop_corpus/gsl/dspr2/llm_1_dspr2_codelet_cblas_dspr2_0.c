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
if (N <= 0) return;
const int total_elements = (N * (N + 1)) / 2;
for (int idx = 0; idx < total_elements; idx++) {
    int i = 0;
    int temp = idx;
    int remaining = N;
    while (remaining > 0) {
        if (temp < remaining) break;
        temp -= remaining;
        i++;
        remaining--;
    }
    j = i + temp;
    int ix = i * incX;
    int iy = i * incY;
    int jx = j * incX;
    int jy = j * incY;
    const double tmp1 = alpha * X[ix];
    const double tmp2 = alpha * Y[iy];
    Ap[idx] += tmp1 * Y[jy] + tmp2 * X[jx];
}
}
