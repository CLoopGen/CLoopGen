#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float alpha;
extern  float *X;
extern float *Y;
extern int i;
extern  int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float beta = alpha * 2.0f;
    float gamma = alpha * 0.5f;
    for (i = 0; i < m; i++) {
        Y[i] += beta * X[i] - gamma * X[i];
    }
}
