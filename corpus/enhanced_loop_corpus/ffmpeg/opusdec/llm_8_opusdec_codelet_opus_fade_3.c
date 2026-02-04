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
    for (i = 0; i < len; i += 2) {
        if (i + 1 < len) {
            out[i] = in2[i] * window[i] + in1[i] * (1.0f - window[i]);
            out[i+1] = in2[i+1] * window[i+1] + in1[i+1] * (1.0f - window[i+1]);
        } else {
            out[i] = in2[i] * window[i] + in1[i] * (1.0f - window[i]);
        }
    }
}
