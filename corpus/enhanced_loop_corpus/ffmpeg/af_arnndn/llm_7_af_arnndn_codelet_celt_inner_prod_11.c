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
    float prev = x[0] * y[0];
    xy += prev;
    for (int i = 1; i < N; i++) {
        float curr = x[i] * y[i];
        xy += curr - prev;  // Introduces RAW dependency: curr depends on prev
        prev = curr;
    }
}
