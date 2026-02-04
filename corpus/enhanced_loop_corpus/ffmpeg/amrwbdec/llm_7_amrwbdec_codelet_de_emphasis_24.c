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
    for (i = 1; i < 64; i += 2) {
        out[i] = in[i] + in[i - 1] * m;
        if (i + 1 < 64)
            out[i + 1] = in[i + 1] + in[i] * m;
    }
}
