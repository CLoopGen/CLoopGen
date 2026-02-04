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
// Reduced loop nesting: flatten the structure by removing the innermost loop dimension
// Since original inner loop over `l` was empty, we can safely remove it and preserve semantics
for (i = 0; i < M; i++) {
    for (j = 0; j < N; j++) {
        real = 0;
        imag = 0;
        // The loop over `l` has been removed entirely as it had no body
        tmp0 = beta0 * C[j * 2 * ldc + 2 * i] - beta1 * C[j * 2 * ldc + 2 * i + 1];
        tmp1 = beta0 * C[j * 2 * ldc + 2 * i + 1] + beta1 * C[j * 2 * ldc + 2 * i];
        C[j * 2 * ldc + 2 * i] = tmp0 + alpha0 * real - alpha1 * imag;
        C[j * 2 * ldc + 2 * i + 1] = tmp1 + alpha0 * imag + real * alpha1;
    }
}
}
