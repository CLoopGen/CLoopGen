#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int K;
extern  double alpha;
extern double *C;
extern  int ldc;
extern int i;
extern int j;
extern int k;
extern int n1;
extern int n2;
extern int ldf;
extern int ldg;
extern  double *F;
extern  double *G;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double temp_accum[n1]; // Introduce local accumulation array to modify data dependency pattern
for (i = 0; i < n1; i++) {
    temp_accum[i] = 0.;
}
for (j = 0; j < n2; j++) {
    for (i = 0; i < n1; i++) {
        double temp = 0.;
        for (k = 0; k < K; k++) {
            temp += F[ldf * k + i] * G[ldg * j + k];
        }
        temp_accum[i] = temp; // Introduce temporary write (WAW) within i-loop, no loop-carried dep across j
    }
    for (i = 0; i < n1; i++) {
        C[ldc * i + j] += alpha * temp_accum[i]; // Final update to C after inner computation
    }
}
}
