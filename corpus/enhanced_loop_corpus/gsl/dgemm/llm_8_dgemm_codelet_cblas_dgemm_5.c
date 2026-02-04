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
for (i = 0; i < n1; i++) {
    for (j = 0; j < n2; j++) {
        double temp1 = 0.;
        double temp2 = 0.;
        double temp3 = 0.;
        double temp4 = 0.;
        int k = 0;
        for (; k + 3 < K; k += 4) {
            temp1 += F[ldf * k     + i] * G[ldg * j + k];
            temp2 += F[ldf * (k+1) + i] * G[ldg * j + (k+1)];
            temp3 += F[ldf * (k+2) + i] * G[ldg * j + (k+2)];
            temp4 += F[ldf * (k+3) + i] * G[ldg * j + (k+3)];
        }
        temp1 += temp2 + temp3 + temp4;
        for (; k < K; k++) {
            temp1 += F[ldf * k + i] * G[ldg * j + k];
        }
        C[ldc * i + j] += alpha * temp1;
    }
}
}
