#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float alpha;
extern  float *A;
extern  int lda;
extern  float *B;
extern  int ldb;
extern float *C;
extern  int ldc;
extern int i;
extern int j;
extern int k;
extern int n1;
extern int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n1; i++) {
    float * restrict Ci = &C[i * ldc];
    const float * restrict Bi = &B[i * ldb];
    for (j = 0; j < n2; j++) {
        const float temp1 = alpha * Bi[j];
        float temp2 = 0.;
        Ci[j] += temp1 * A[j * lda + j];
        const float * restrict Aj_row = &A[j * lda];
        for (k = j + 1; k < n2; k++) {
            const float Ajk = Aj_row[k];
            Ci[k] += temp1 * Ajk;
            temp2 += Bi[k] * Ajk;
        }
        Ci[j] += alpha * temp2;
    }
}
}
