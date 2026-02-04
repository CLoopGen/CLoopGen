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
    int j;
    for (j = 0; j < 1; j++) {
        for (i = 0; i < 30; i++) {
            float s = i * (1.0f / 30.0f);
            out_data[i] = tmpbuf[i] + s * (synth[i] - tmpbuf[i]);
        }
    }
}
