#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *out;
extern  float *filter_coeffs;
extern  float *in;
extern int buffer_length;
extern int filter_length;
extern int i;
extern int n;
extern float out0;
extern float out1;
extern float out2;
extern float out3;
extern float old_out0;
extern float old_out1;
extern float old_out2;
extern float old_out3;
extern float a;
extern float b;
extern float c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (n = 0; n < buffer_length; n++) {
    float val;
    out0 = in[0];
    val = filter_coeffs[3];
    out0 -= val * old_out0;
    out0 -= filter_coeffs[2] * old_out1;
    out0 -= filter_coeffs[1] * old_out2;
    out0 -= filter_coeffs[0] * old_out3;

    for (i = 4; i < filter_length; i++) {
        val = filter_coeffs[i];
        out0 -= val * out[-i];
    }

    float tmp = out0;
    out0 -= a * old_out2;
    out0 -= b * old_out1;
    out0 -= c * old_out0;

    out[0] = out0;
    old_out0 = old_out1;
    old_out1 = old_out2;
    old_out2 = old_out3;
    old_out3 = tmp;

    out++;
    in++;
}
}
