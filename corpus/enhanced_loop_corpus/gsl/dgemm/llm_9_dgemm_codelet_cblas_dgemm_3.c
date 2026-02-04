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
if (K > 0 && n1 > 0 && n2 > 0) {
    for (i = 0; i < n1; i += 2) {
        for (j = 0; j < n2; j += 2) {
            for (int ii = 0; ii < 2 && (i + ii) < n1; ii++) {
                for (int jj = 0; jj < 2 && (j + jj) < n2; jj++) {
                    double temp = 0.;
                    for (k = 0; k < K; k++) {
                        temp += F[ldf * (i + ii) + k] * G[ldg * (j + jj) + k];
                    }
                    C[ldc * (i + ii) + (j + jj)] += alpha * temp;
                }
            }
        }
    }
}
}
