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
        for (k = 0; k < K; k += 4) {
            float temp0 = F[ldf * i + k] * G[ldg * j + k];
            float temp1 = 0.0f, temp2 = 0.0f, temp3 = 0.0f;
            if (k + 1 < K) temp1 = F[ldf * i + k + 1] * G[ldg * j + k + 1];
            if (k + 2 < K) temp2 = F[ldf * i + k + 2] * G[ldg * j + k + 2];
            if (k + 3 < K) temp3 = F[ldf * i + k + 3] * G[ldg * j + k + 3];
            C[ldc * i + j] += alpha * (temp0 + temp1 + temp2 + temp3);
        }
    }
}
}
