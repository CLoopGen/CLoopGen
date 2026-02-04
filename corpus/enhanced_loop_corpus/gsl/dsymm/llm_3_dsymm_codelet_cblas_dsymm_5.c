#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double alpha;
extern  double *A;
extern  int lda;
extern  double *B;
extern  int ldb;
extern double *C;
extern  int ldc;
extern int i;
extern int j;
extern int k;
extern int n1;
extern int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
const ptrdiff_t strideA = 1;
const ptrdiff_t strideB = 1;
const ptrdiff_t strideC = 1;
for (i = 0; i < n1; i++) {
    double * restrict Ci = &C[i * ldc];
    double * restrict Bi = &B[i * ldb];
    for (j = 0; j < n2; j++) {
        const double temp1 = alpha * Bi[j];
        double temp2 = 0.;
        double * restrict Aj = &A[j * lda];
        for (k = 0; k < j; k++) {
            const double Ajk = Aj[k];
            Ci[k] += temp1 * Ajk;
            temp2 += Bi[k] * Ajk;
        }
        Ci[j] += temp1 * Aj[j] + alpha * temp2;
    }
}
}
