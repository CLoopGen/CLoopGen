#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int K;
extern  float alpha;
extern float *C;
extern  int ldc;
extern int i;
extern int j;
extern int k;
extern int n1;
extern int n2;
extern int ldf;
extern int ldg;
extern  float *F;
extern  float *G;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n1; i++) {
    for (j = 0; j < n2; j++) {
        float temp = 0.;
        if (i % 2 == 0) {
            for (k = 0; k < K; k++) {
                temp += F[ldf * i + k] * G[ldg * j + k];
            }
        } else {
            for (k = K - 1; k >= 0; k--) {
                temp += F[ldf * i + k] * G[ldg * j + k];
            }
        }
        C[ldc * i + j] += alpha * temp;
    }
}
}
