#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double alpha;
extern  double *X;
extern double *Y;
extern int i;
extern  int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = m; i + 3 < N; i += 4) {
    int idx0 = i;
    int idx1 = i + 1;
    int idx2 = i + 2;
    int idx3 = i + 3;
    Y[idx0] += alpha * X[idx0];
    Y[idx1] += alpha * X[idx1];
    Y[idx2] += alpha * X[idx2];
    Y[idx3] += alpha * X[idx3];
}
}
