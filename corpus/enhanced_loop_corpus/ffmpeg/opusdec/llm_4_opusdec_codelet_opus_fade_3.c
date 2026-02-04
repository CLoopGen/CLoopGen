#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *out;
extern  float *in1;
extern  float *in2;
extern  float *window;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i++) {
        float w = window[i];
        if (w == 0.0f) {
            out[i] = in1[i];
        } else if (w == 1.0f) {
            out[i] = in2[i];
        } else {
            out[i] = in2[i] * w + in1[i] * (1.0f - w);
        }
    }
}
