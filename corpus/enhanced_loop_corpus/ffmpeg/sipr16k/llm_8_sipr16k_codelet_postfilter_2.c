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
    float alpha = 1.0f / 30;
    for (i = 0; i < 15; i++) {
        s = i * alpha;
        out_data[i] = tmpbuf[i] + s * (synth[i] - tmpbuf[i]);
        out_data[29 - i] = tmpbuf[29 - i] + (1.0f - s) * (synth[29 - i] - tmpbuf[29 - i]);
    }
}
