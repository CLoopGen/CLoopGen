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
    float temp_i[256]; // Assuming max n2 is bounded; could be dynamically sized if needed
    for (j = 0; j < n2; j++) {
        temp_i[j] = 0.0f;
        for (k = 0; k < K; k++) {
            temp_i[j] += F[ldf * i + k] * G[ldg * j + k];
        }
    }
    for (j = 0; j < n2; j++) {
        C[ldc * i + j] += alpha * temp_i[j];
    }
}
}
