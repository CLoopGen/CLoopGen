#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *X;
extern  float *Y;
extern int N;
extern int i;
extern float e[2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (N <= 0) return;
int chunk = 1;
for (i = 0; i < N; i += chunk) {
    int end = i + chunk;
    if (end > N) end = N;
    for (int k = i; k < end; k++) {
        e[0] += X[k] * X[k];
        e[1] += Y[k] * Y[k];
    }
}
}
