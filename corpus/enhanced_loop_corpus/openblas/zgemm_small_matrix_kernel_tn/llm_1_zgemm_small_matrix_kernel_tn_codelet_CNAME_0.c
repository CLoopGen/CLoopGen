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
for (i = 0; i < M; i++) {
    real = 0;
    imag = 0;
    for (l = 0; l < K; l++) {
        for (j = 0; j < N; j++) {
            int index = j * 2 * ldc + 2 * i;
            tmp0 = beta0 * C[index] - beta1 * C[index + 1];
            tmp1 = beta0 * C[index + 1] + beta1 * C[index];
            C[index] = tmp0 + alpha0 * real - alpha1 * imag;
            C[index + 1] = tmp1 + alpha0 * imag + real * alpha1;
        }
    }
}
}
