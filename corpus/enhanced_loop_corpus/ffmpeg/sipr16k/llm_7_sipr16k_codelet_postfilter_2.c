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
    float acc = 0;
    for (i = 0; i < 30; i++) {
        acc += 1. / 30;
        out_data[i] = tmpbuf[i] + acc * (synth[i] - tmpbuf[i]);
    }
}
