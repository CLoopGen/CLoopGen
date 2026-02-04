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
for (j = 0; j < N; j++) {
    int col_offset = j * 2 * ldc;
    for (i = 0; i < M; i++) {
        real = 0;
        imag = 0;
        for (l = 0; l < K; l++) {
        }
        int addr = col_offset + 2 * i;
        float c0 = C[addr];
        float c1 = C[addr + 1];
        tmp0 = beta0 * c0 - beta1 * c1;
        tmp1 = beta0 * c1 + beta1 * c0;
        C[addr] = tmp0 + alpha0 * real - alpha1 * imag;
        C[addr + 1] = tmp1 + alpha0 * imag + alpha1 * real;
    }
}
}
