#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *output;
extern  int N;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < N; i += 2) {
        if (i < N) output[i] = (0 > output[i]) ? 0 : output[i];
        if (i + 1 < N) output[i + 1] = (0 > output[i + 1]) ? 0 : output[i + 1];
    }
}
