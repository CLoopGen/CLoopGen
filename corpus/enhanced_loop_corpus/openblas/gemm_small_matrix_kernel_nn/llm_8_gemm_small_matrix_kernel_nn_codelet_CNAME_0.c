#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG M;
extern BLASLONG N;
extern BLASLONG K;
extern float *A;
extern BLASLONG lda;
extern float alpha;
extern float *B;
extern BLASLONG ldb;
extern float beta;
extern float *C;
extern BLASLONG ldc;
extern BLASLONG i;
extern BLASLONG j;
extern BLASLONG k;
extern float result;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < M; i++) {
    for (j = 0; j < N; j++) {
        result = 0.;
        float temp_C = C[i + j * ldc]; // Introduce local copy to remove WAW and RAW hazards across iterations
        for (k = 0; k < K; k++) {
            result += A[i + k * lda] * B[k + j * ldb];
        }
        C[i + j * ldc] = temp_C * beta + alpha * result; // Use local value to decouple read/write of C
    }
}
}
