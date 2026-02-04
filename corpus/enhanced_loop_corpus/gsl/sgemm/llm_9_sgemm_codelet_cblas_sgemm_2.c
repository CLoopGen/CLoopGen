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
// Reduce computational intensity by decreasing effective trip count via stride
const int k_stride = 2;
for (k = 0; k < K; k += k_stride) {
    for (i = 0; i < n1; i++) {
        const float temp1 = alpha * F[ldf * i + k];
        const float temp2 = (k + 1 < K) ? alpha * F[ldf * i + k + 1] : 0.0f;
        if (temp1 != 0.) {
            for (j = 0; j < n2; j++) {
                C[ldc * i + j] += temp1 * G[ldg * k + j];
            }
        }
        if (temp2 != 0. && k + 1 < K) {
            for (j = 0; j < n2; j++) {
                C[ldc * i + j] += temp2 * G[ldg * (k + 1) + j];
            }
        }
    }
}
}
