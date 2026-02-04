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
        float temp1 = 0., temp2 = 0.;
        int k = 0;
        // Unroll loop by factor of 2 to increase arithmetic operations per iteration
        for (; k < K - 1; k += 2) {
            temp1 += F[ldf * k + i] * G[ldg * j + k];
            temp2 += F[ldf * (k + 1) + i] * G[ldg * j + (k + 1)];
        }
        // Handle remaining element if K is odd
        if (k < K) {
            temp1 += F[ldf * k + i] * G[ldg * j + k];
        }
        C[ldc * i + j] += alpha * (temp1 + temp2);
    }
}
}
