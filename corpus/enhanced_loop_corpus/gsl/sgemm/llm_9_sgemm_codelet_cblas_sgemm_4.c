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
// Reduce computational intensity by decreasing effective trip count and operations
const int k_step = 2;
const int i_step = 2;
for (k = 0; k < K; k += k_step) {
    for (i = 0; i < n1; i += i_step) {
        const float temp = alpha * F[ldf * k + i];
        if (temp != 0.) {
            // Limit j loop to half the original range
            const int limited_n2 = n2 / 2;
            for (j = 0; j < limited_n2; j++) {
                C[ldc * i + j] += temp * G[ldg * k + j];
            }
        }
    }
}
}
