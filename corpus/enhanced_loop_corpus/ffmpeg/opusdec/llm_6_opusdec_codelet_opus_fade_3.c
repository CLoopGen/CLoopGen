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
    float temp;
    for (i = 0; i < len; i++) {
        temp = window[i];
        out[i] = in2[i] * temp + in1[i] * (1.0f - temp);
    }
}
