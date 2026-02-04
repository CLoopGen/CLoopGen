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
for (k = 0; k < K; k++) {
    for (i = 0; i < n1; i++) {
        const double temp = alpha * F[ldf * i + k];
        if (temp != 0.) {
            for (j = 0; j < n2; j++) {
                C[ldc * i + j] += temp * G[ldg * k + j];
            }
        }
    }
}

}
