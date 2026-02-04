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
double *Ap = A;
double *Bp, *Cp;
for (i = 0; i < n1; i++) {
    Bp = B + i;
    Cp = C + i * ldc;
    for (j = 0; j < n2; j++) {
        const double temp1 = alpha * Bp[ldb * j];
        double temp2 = 0.;
        Cp[j] += temp1 * Ap[j * lda + j];
        for (k = j + 1; k < n2; k++) {
            const double Ajk = Ap[j * lda + k];
            Cp[k] += temp1 * Ajk;
            temp2 += Bp[ldb * k] * Ajk;
        }
        Cp[j] += alpha * temp2;
    }
}
}
