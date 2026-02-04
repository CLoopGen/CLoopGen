#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *X;
extern int N;
extern int i;
extern float g;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (N <= 0) return;
    g += X[0] * X[0];
    for (i = 1; i < N; i++)
        g += X[i] * X[i];
}
