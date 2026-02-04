#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *out_data;
extern float *synth;
extern float *tmpbuf;
extern float s;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse sequential access
    // Traverse arrays from last to first element
    float scale = 1.0f / 30;
    for (i = 29, s = 29 * scale; i >= 0; i--, s -= scale)
        out_data[i] = tmpbuf[i] + s * (synth[i] - tmpbuf[i]);
}
