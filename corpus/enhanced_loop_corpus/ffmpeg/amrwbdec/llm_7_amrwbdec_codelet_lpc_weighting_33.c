#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *out;
extern  float *lpc;
extern float gamma;
extern int size;
extern int i;
extern float fac;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float prev_out = 0.0f;
    for (i = 0; i < size; i++) {
        float current_val = lpc[i] * fac;
        out[i] = current_val + prev_out;
        prev_out = current_val;
        fac *= gamma;
    }
}
