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
for (k = 0; k < K; k++) {
    for (i = 0; i < n1; i++) {
        const float temp = alpha * F[ldf * i + k];
        if (temp != 0.) {
            j = 0;
            // Unroll factor of 4 with cleanup
            for (; j <= n2 - 4; j += 4) {
                C[ldc * i + j] += temp * G[ldg * k + j];
                C[ldc * i + j + 1] += temp * G[ldg * k + j + 1];
                C[ldc * i + j + 2] += temp * G[ldg * k + j + 2];
                C[ldc * i + j + 3] += temp * G[ldg * k + j + 3];
            }
            // Handle remainder
            for (; j < n2; j++) {
                C[ldc * i + j] += temp * G[ldg * k + j];
            }
        }
    }
}
}
