#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *out;
extern float *in;
extern float m;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp = out[0] * m;
    for (i = 1; i < 64; i++) {
        temp = in[i] + temp;
        out[i] = temp;
    }
}
