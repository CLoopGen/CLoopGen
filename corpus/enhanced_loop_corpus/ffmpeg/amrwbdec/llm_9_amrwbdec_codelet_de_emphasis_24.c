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
for (i = 1; i < 32; i++) {
    out[i] = in[i] + out[i - 1] * m;
    out[i + 32] = in[i + 32] + out[i + 31] * m;
}
}
