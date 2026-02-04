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
    float inv_step = 1.0f / 60;
    for (i = 0; i < 60; i += 2) {
        s = i * inv_step;
        float diff = synth[i/2] - tmpbuf[i/2];
        float weighted = s * diff;
        out_data[i/2] = tmpbuf[i/2] + weighted;
    }
}
