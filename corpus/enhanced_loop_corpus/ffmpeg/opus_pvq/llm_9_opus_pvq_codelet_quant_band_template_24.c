#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *Y;
extern int N;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float scale = -1.0f;
    for (i = 0; i < N * 2; i++) {
        int idx = i / 2;
        Y[idx] = (i % 2 == 0) ? Y[idx] * scale : Y[idx] + 0.0f;
    }
}
