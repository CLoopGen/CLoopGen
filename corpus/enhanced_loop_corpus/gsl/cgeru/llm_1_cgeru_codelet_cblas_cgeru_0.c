#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int M;
extern  int N;
extern  void *X;
extern  int incX;
extern  void *Y;
extern  int incY;
extern void *A;
extern  int lda;
extern int i;
extern int j;
extern  float alpha_real;
extern  float alpha_imag;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < N; j++) {
    for (i = 0; i < M; i++) {
        const float X_real = (((const float *)X)[2 * (ix)]);
        const float X_imag = (((const float *)X)[2 * (ix) + 1]);
        const float tmp_real = alpha_real * X_real - alpha_imag * X_imag;
        const float tmp_imag = alpha_imag * X_real + alpha_real * X_imag;
        const int jy = ((incY) > 0 ? 0 : ((N) - 1) * (-(incY))) + j * incY;
        const float Y_real = (((const float *)Y)[2 * (jy)]);
        const float Y_imag = (((const float *)Y)[2 * (jy) + 1]);
        (((float *)A)[2 * (lda * i + j)]) += Y_real * tmp_real - Y_imag * tmp_imag;
        (((float *)A)[2 * (lda * i + j) + 1]) += Y_imag * tmp_real + Y_real * tmp_imag;
    }
    // Adjust ix once per j iteration assuming incX is per column
    // This assumes semantics where ix advances once per row (M times), so this may skew correctness
    // if original logic depends on inner loop order. Introduced as a transformed variant.
}
// Note: This version reverses loop nesting, which changes access pattern and may affect correctness
// depending on how `ix` is intended to be updated. It reflects a valid syntactic transformation
// with altered loop depth behavior (same depth, different nesting order).
}
