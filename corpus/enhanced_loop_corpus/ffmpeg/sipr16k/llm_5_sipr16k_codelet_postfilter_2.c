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
    float step = 1.0f / 30.0f;
    s = 0.0f;
    for (i = 0; i < 30; i++) {
        if (i % 2 == 0) {
            out_data[i] = tmpbuf[i] + s * (synth[i] - tmpbuf[i]);
        } else {
            out_data[i] = synth[i]; // Alternate behavior: use synth directly on odd indices
        }
        s += step;
    }
}
