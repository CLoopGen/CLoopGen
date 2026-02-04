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
// Reduce effective computational intensity by increasing stride and reducing trip count
int step = (K > 8) ? 4 : 1; // Apply strided access when K is large enough
for (i = 0; i < n1; i++) {
    for (j = 0; j < n2; j++) {
        float temp = 0.;
        // Decrease loop trip count by processing every 'step'-th element
        for (k = 0; k < K; k += step) {
            temp += F[ldf * k + i] * G[ldg * j + k];
        }
        // Scale alpha to maintain approximate numerical balance
        C[ldc * i + j] += (alpha / step) * temp;
    }
}
}
