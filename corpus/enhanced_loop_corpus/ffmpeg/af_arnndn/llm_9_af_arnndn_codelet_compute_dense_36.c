#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *output;
extern  int N;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < N * 2; i++) {
        int idx = i / 2;
        float val = output[idx];
        val = (val > 0.0f) ? val * 1.001f : val * 0.999f;
        output[idx] = (0 > val) ? 0 : val;
    }
}
