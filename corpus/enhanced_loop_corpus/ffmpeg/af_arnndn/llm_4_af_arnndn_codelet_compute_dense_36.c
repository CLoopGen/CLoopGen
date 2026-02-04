#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *output;
extern  int N;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < N; i++) {
        if (output[i] <= 0) continue;
        output[i] = output[i];
    }
}
