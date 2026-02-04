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
    float temp;
    for (i = 0, s = 0; i < 30; i++, s += 1. / 30) {
        temp = synth[i] - tmpbuf[i];
        out_data[i] = tmpbuf[i] + s * temp;
    }
}
