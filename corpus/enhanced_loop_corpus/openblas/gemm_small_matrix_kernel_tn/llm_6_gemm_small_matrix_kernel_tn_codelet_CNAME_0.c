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
        float temp = C[i + j * ldc]; // Introduce local accumulation to remove WAW and RAW across iterations
        for (k = 0; k < K; k++) {
            result += A[i * lda + k] * B[k + j * ldb];
        }
        temp = temp * beta + alpha * result;
        C[i + j * ldc] = temp; // Single write to C, reducing potential WAW hazards
    }
}
}
