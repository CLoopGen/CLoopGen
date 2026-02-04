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
float temp_accum = 0.0f;
float prev_C = C[0];
for (i = 0; i < n1; i++) {
    for (j = 0; j < n2; j++) {
        float local_temp = 0.0f;
        for (k = 0; k < K; k++) {
            local_temp += F[ldf * i + k] * G[ldg * j + k];
        }
        int idx = ldc * i + j;
        temp_accum += C[idx]; // Introduce WAW and RAW dependency via temp_accum
        C[idx] = alpha * local_temp + prev_C; // WAR: write after read of prev_C; depends on previous iteration
        prev_C = temp_accum; // Loop-carried dependency introduced
    }
}
}
