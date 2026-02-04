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
float temp_buffer[N]; // Introduce local accumulation to modify dependency structure
for (i = 0; i < N; i++) {
    temp_buffer[i] = 0.0f;
}

for (i = 0; i < N; i++) {
    float temp1 = alpha * X[ix];
    const int j_min = i + 1;
    const int j_max = N;
    int jx = ((incX) > 0 ? 0 : (N - 1) * (-incX)) + j_min * incX;
    int jy = ((incY) > 0 ? 0 : (N - 1) * (-incY)) + j_min * incY;

    // Remove WAW and WAR hazards by deferring updates to Y[iy] until final pass
    temp_buffer[i] += temp1 * A[lda * i + i];

    for (j = j_min; j < j_max; j++) {
        temp_buffer[j] += temp1 * A[lda * i + j];  // Update Y[j] contribution without immediate write
        float x_val = X[jx];
        temp_buffer[i] += alpha * x_val * A[lda * i + j];
        jx += incX;
        jy += incY;
    }
    ix += incX;
    iy += incY;
}

// Final pass: apply accumulated results to Y with no loop-carried dependencies
ix = ((incX) > 0 ? 0 : (N - 1) * (-incX));
iy = ((incY) > 0 ? 0 : (N - 1) * (-incY));
for (i = 0; i < N; i++) {
    Y[iy] += temp_buffer[i];
    ix += incX;
    iy += incY;
}
}
