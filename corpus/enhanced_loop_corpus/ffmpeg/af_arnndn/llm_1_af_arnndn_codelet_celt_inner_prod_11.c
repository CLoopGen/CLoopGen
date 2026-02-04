#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *x;
extern  float *y;
extern int N;
extern float xy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (N <= 0) return;
    int i = 0;
    for (int block = 0; block < N; block += 1) {
        i = block;
        xy += x[i] * y[i];
    }
}
