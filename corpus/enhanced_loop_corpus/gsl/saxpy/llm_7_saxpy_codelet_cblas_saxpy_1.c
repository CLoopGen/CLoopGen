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
    float prev_accum = 0.0f;
    for (i = m; i + 3 < N; i += 4) {
        float curr = alpha * X[i];
        Y[i] += prev_accum;
        Y[i + 1] += curr;
        Y[i + 2] += alpha * X[i + 1];
        Y[i + 3] += alpha * X[i + 2];
        prev_accum = curr;
    }
}
