#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float alpha;
extern  float *X;
extern float *Y;
extern int i;
extern  int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = m; i + 3 < N; i += 4) {
    if (X[i] > 0.0f) {
        Y[i] += alpha * X[i];
    }
    if (X[i + 1] > 0.0f) {
        Y[i + 1] += alpha * X[i + 1];
    }
    if (X[i + 2] > 0.0f) {
        Y[i + 2] += alpha * X[i + 2];
    }
    if (X[i + 3] > 0.0f) {
        Y[i + 3] += alpha * X[i + 3];
    }
}
}
