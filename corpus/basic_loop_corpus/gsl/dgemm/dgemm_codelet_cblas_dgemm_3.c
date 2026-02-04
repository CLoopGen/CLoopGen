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
        double temp = 0.;
        for (k = 0; k < K; k++) {
            temp += F[ldf * i + k] * G[ldg * j + k];
        }
        C[ldc * i + j] += alpha * temp;
    }
}

}
