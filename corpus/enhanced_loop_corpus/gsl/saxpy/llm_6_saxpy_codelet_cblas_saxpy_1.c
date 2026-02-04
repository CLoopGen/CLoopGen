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
        float temp1 = alpha * X[i];
        float temp2 = alpha * X[i + 1];
        float temp3 = alpha * X[i + 2];
        float temp4 = alpha * X[i + 3];
        Y[i] += temp1;
        Y[i + 1] += temp2;
        Y[i + 2] += temp3;
        Y[i + 3] += temp4;
    }
}
