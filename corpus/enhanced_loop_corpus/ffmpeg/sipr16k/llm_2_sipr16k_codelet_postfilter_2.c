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
    // Variant 1: Strided memory access (step of 2, unrolled-like pattern)
    // Access elements with a stride of 2, processing even indices only.
    float scale = 1.0f / 30;
    for (i = 0, s = 0; i < 30; i += 2, s += 2 * scale) {
        if (i + 1 < 30) {
            out_data[i]     = tmpbuf[i]     + s           * (synth[i]     - tmpbuf[i]);
            out_data[i + 1] = tmpbuf[i + 1] + (s + scale) * (synth[i + 1] - tmpbuf[i + 1]);
        } else {
            out_data[i] = tmpbuf[i] + s * (synth[i] - tmpbuf[i]);
        }
    }
}
