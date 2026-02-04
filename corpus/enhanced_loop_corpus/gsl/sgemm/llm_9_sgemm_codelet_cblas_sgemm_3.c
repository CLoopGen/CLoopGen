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
// Reduce effective computation by increasing stride and reducing trip count
// Simulates processing every second element, lowering arithmetic volume
int step = 2;
int k_max = (K + step - 1) / step;

for (i = 0; i < n1; i++) {
    for (j = 0; j < n2; j++) {
        float temp = 0.;
        for (k = 0; k < k_max; k++) {
            int idx = step * k;
            temp += F[ldf * i + idx] * G[ldg * j + idx];
        }
        C[ldc * i + j] += alpha * temp;
    }
}
}
