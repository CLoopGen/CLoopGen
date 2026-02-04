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
    if (len > 0) {
        out[0] = in2[0] * window[0] + in1[0] * (1.0f - window[0]);
        for (i = 1; i < len; i++) {
            out[i] = in2[i] * window[i] + in1[i] * (1.0f - window[i]);
        }
    }
}
