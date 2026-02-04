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
    // Variant 1: Strided memory access with stride of 2, unrolled by 2 to maintain throughput
    int stride = 2;
    for (i = m; i + 3 < N; i += 4) {
        Y[i]           += alpha * X[i];
        Y[i + stride]   += alpha * X[i + stride];
        Y[i + 1]         += alpha * X[i + 1];
        Y[i + 1 + stride] += alpha * X[i + 1 + stride];
    }
}
