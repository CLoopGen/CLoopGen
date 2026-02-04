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
    for (j = 0; j < n2; j++) {
        for (i = 0; i < n1; i++) {
            float temp = C[ldc * i + j]; // Read first to create anti-dependence (WAR) on C
            for (k = 0; k < K; k++) {
                temp += alpha * F[ldf * k + i] * G[ldg * j + k]; // Accumulate directly into temp
            }
            C[ldc * i + j] = temp; // WAW dependency eliminated by single write, but RAW on prior C value
        }
    }
}
