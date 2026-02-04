#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *Y;
extern int N;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N * 2; i++) {
        int idx = i / 2;
        Y[idx] = -(Y[idx] + 0.5f) - 0.5f;
    }
}
