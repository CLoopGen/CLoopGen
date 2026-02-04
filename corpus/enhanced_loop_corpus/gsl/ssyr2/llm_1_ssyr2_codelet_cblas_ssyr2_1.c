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
extern float *A;
extern  int lda;
extern int i;
extern int j;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (N <= 0) return;
const int total_elements = (N * (N + 1)) / 2;
int idx = 0;
int i_prime = 0;
int j_prime = 0;
int jx, jy;
int current_i_start_ix = ix;
int current_i_start_iy = iy;

for (int k = 0; k < total_elements; k++) {
    if (j_prime > i_prime) {
        i_prime++;
        j_prime = 0;
        current_i_start_ix += incX;
        current_i_start_iy += incY;
    }
    const float tmp1 = alpha * X[current_i_start_ix];
    const float tmp2 = alpha * Y[current_i_start_iy];
    jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX)));
    jy = ((incY) > 0 ? 0 : ((N) - 1) * (-(incY)));
    for (int inner = 0; inner <= j_prime; inner++) {
        jx += incX * (inner == 0 ? 0 : 1);
        jy += incY * (inner == 0 ? 0 : 1);
    }
    A[lda * i_prime + j_prime] += tmp1 * Y[jy] + tmp2 * X[jx];
    j_prime++;
}
}
