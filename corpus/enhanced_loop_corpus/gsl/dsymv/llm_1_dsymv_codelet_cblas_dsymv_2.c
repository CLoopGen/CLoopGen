#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double alpha;
extern  double *A;
extern  int lda;
extern  double *X;
extern  int incX;
extern double *Y;
extern  int incY;
extern int i;
extern int j;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (N <= 0) return;
double temp1, temp2;
const int abs_incX = (incX > 0 ? incX : -incX);
const int abs_incY = (incY > 0 ? incY : -incY);
int base_offset_X = (incX > 0 ? 0 : (N - 1) * (-incX));
int base_offset_Y = (incY > 0 ? 0 : (N - 1) * (-incY));

for (i = 0; i < N; i++) {
    int current_ix = base_offset_X + i * incX;
    int current_iy = base_offset_Y + i * incY;
    temp1 = alpha * X[current_ix];
    temp2 = 0.0;
    Y[current_iy] += temp1 * A[lda * i + i];

    for (int k = 0; k < N - i - 1; k++) {
        j = i + 1 + k;
        int jx = base_offset_X + j * incX;
        int jy = base_offset_Y + j * incY;
        int a_index = lda * i + j;

        Y[jy] += temp1 * A[a_index];
        temp2 += X[jx] * A[a_index];
    }

    Y[current_iy] += alpha * temp2;
}
}
