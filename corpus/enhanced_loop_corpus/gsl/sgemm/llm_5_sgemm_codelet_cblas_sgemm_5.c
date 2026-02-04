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
        if (K > 0) {
            k = 0;
            if (K % 2 == 0) {
                for (; k < K; k += 2) {
                    temp += F[ldf * k + i] * G[ldg * j + k] +
                            F[ldf * (k+1) + i] * G[ldg * j + (k+1)];
                }
            } else {
                for (; k < K - 1; k += 2) {
                    temp += F[ldf * k + i] * G[ldg * j + k] +
                            F[ldf * (k+1) + i] * G[ldg * j + (k+1)];
                }
                temp += F[ldf * k + i] * G[ldg * j + k];
            }
            C[ldc * i + j] += alpha * temp;
        }
    }
}
}
