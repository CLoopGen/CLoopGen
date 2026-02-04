#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int K;
extern  double alpha;
extern double *C;
extern  int ldc;
extern int i;
extern int j;
extern int k;
extern int n1;
extern int n2;
extern int ldf;
extern int ldg;
extern  double *F;
extern  double *G;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *restrict c_ptr;
    const double alph = alpha;
    for (i = 0; i < n1; i++) {
        for (j = 0; j < n2; j++) {
            c_ptr = &C[ldc * i + j];
            double sum = 0.0;
            for (k = 0; k < K; k++) {
                sum += F[ldf * i + k] * G[ldg * j + k];
            }
            *c_ptr = *c_ptr + alph * sum;
        }
    }
}
