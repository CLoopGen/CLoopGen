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
        double temp1 = alpha * X[i];
        double temp2 = alpha * X[i + 1];
        double temp3 = alpha * X[i + 2];
        double temp4 = alpha * X[i + 3];
        Y[i] += temp1;
        Y[i + 1] += temp2;
        Y[i + 2] += temp3;
        Y[i + 3] += temp4;
    }
}
