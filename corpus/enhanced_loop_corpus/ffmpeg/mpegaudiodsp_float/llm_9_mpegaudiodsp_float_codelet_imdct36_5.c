#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *in;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 16; i >= 4; i -= 1) {
        in[i] += in[i - 1];
        in[i] *= 1.1f;
        in[i] -= in[i - 2] * 0.1f;
    }
}
