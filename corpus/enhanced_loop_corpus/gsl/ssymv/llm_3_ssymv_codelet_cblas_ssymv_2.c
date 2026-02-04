#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float alpha;
extern  float *A;
extern  int lda;
extern  float *X;
extern  int incX;
extern float *Y;
extern  int incY;
extern int i;
extern int j;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    float temp1 = alpha * X[i * incX];
    float temp2 = 0.;
    const int j_min = i + 1;
    const int j_max = N;
    Y[i * incY] += temp1 * A[lda * i + i];
    for (j = j_min; j < j_max; j++) {
        const int offset = lda * i + j;
        const int x_index = j * incX;
        const int y_index = j * incY;
        Y[y_index] += temp1 * A[offset];
        temp2 += X[x_index] * A[offset];
    }
    Y[i * incY] += alpha * temp2;
}
}
