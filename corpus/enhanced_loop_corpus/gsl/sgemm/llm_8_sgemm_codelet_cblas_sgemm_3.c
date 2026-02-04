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
        float temp1 = 0.;
        float temp2 = 0.;
        float temp3 = 0.;
        float temp4 = 0.;
        int k;
        // Unroll loop by factor of 4 to increase computational intensity
        for (k = 0; k + 3 < K; k += 4) {
            temp1 += F[ldf * i + k + 0] * G[ldg * j + k + 0];
            temp2 += F[ldf * i + k + 1] * G[ldg * j + k + 1];
            temp3 += F[ldf * i + k + 2] * G[ldg * j + k + 2];
            temp4 += F[ldf * i + k + 3] * G[ldg * j + k + 3];
        }
        // Accumulate the partial sums
        float sum = temp1 + temp2 + temp3 + temp4;
        // Handle remaining elements
        for (; k < K; k++) {
            sum += F[ldf * i + k] * G[ldg * j + k];
        }
        C[ldc * i + j] += alpha * sum;
    }
}
}
