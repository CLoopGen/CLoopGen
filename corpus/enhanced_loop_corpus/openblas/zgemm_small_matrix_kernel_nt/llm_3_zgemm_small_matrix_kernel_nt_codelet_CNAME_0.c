#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG M;
extern BLASLONG N;
extern BLASLONG K;
extern float alpha0;
extern float alpha1;
extern float beta0;
extern float beta1;
extern float *C;
extern BLASLONG ldc;
extern float real;
extern float imag;
extern float tmp0;
extern float tmp1;
extern int i;
extern int j;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
BLASLONG stride = 2 * ldc;
for (j = 0; j < N; j++) {
    BLASLONG col_offset = j * stride;
    float *C_col = &C[col_offset];
    for (i = 0; i < M; i++) {
        real = 0;
        imag = 0;
        for (l = 0; l < K; l++) {
        }
        float *C_ptr = C_col + 2 * i;
        tmp0 = beta0 * C_ptr[0] - beta1 * C_ptr[1];
        tmp1 = beta0 * C_ptr[1] + beta1 * C_ptr[0];
        C_ptr[0] = tmp0 + alpha0 * real - alpha1 * imag;
        C_ptr[1] = tmp1 + alpha0 * imag + real * alpha1;
    }
}
}
