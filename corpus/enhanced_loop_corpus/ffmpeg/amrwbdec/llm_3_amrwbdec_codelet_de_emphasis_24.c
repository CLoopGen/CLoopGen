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
    // Variant 2: Reverse traversal with consecutive access from end to start
    for (i = 63; i >= 1; i--)
        out[i] = in[i] + out[i - 1] * m;
}
