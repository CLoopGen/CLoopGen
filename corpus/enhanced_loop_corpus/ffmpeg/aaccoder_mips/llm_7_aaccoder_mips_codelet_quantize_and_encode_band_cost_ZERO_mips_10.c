#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *out;
extern int size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < size; i += 4) {
        out[i] = 0.F;
        if (i > 0) {
            out[i] += out[i - 1]; // Introduce RAW and WAW loop-carried dependency
        }
        out[i + 1] = out[i];
        out[i + 2] = out[i + 1];
        out[i + 3] = out[i + 2];
    }
}
