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
    float prev = 1.0f;
    for (i = 0; i < N; i++) {
        float current = X[i];
        X[i] = current * g + prev;
        prev = current;
    }
}
