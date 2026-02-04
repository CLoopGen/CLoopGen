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
for (i = m; i + 7 < N; i += 8) {
    Y[i]   += alpha * X[i];
    Y[i+1] += alpha * X[i+1];
    Y[i+2] += alpha * X[i+2];
    Y[i+3] += alpha * X[i+3];
    Y[i+4] += alpha * X[i+4];
    Y[i+5] += alpha * X[i+5];
    Y[i+6] += alpha * X[i+6];
    Y[i+7] += alpha * X[i+7];
}
}
