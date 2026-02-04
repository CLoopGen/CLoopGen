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
if (N <= 0) return;
const int total_elements = (N * (N + 1)) / 2;
for (int idx = 0; idx < total_elements; idx++) {
    int i = 0;
    int temp = idx;
    while (temp >= 0) {
        temp -= (i + 1);
        i++;
    }
    i--;
    int j = idx - (i * (i + 1)) / 2;
    const int offset = (i * (i + 1)) / 2 + j;
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX)));
    int jy = ((incY) > 0 ? 0 : ((N) - 1) * (-(incY)));
    for (int k = 0; k <= i; k++) {
        if (k == i && j == j) {
            const double tmp1 = alpha * X[(ix + i * incX)];
            const double tmp2 = alpha * Y[(iy + i * incY)];
            Ap[offset] += tmp1 * Y[jy + j * incY] + tmp2 * X[jx + j * incX];
        }
    }
}
}
