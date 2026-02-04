#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *X;
extern int N;
extern int i;
extern float res;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float prev = 0.0f;
    for (i = 0; i < N; i++) {
        float abs_val = (X[i] >= 0 ? X[i] : -X[i]);
        res += abs_val + prev;
        prev = abs_val;
    }
}
