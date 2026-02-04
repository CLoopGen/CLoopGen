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
for (n = 0; n <= buffer_length - 8; n += 8) {
    float tmp0, tmp1, tmp2, tmp3, tmp4, tmp5;
    float val;
    out0 = in[0];
    out1 = in[1];
    out2 = in[2];
    out3 = in[3];
    float out4 = in[4];
    float out5 = in[5];
    float out6 = in[6];
    float out7 = in[7];

    out0 -= filter_coeffs[2] * old_out1;
    out1 -= filter_coeffs[2] * old_out2;
    out2 -= filter_coeffs[2] * old_out3;
    out4 -= filter_coeffs[2] * old_out1;
    out5 -= filter_coeffs[2] * old_out2;
    out6 -= filter_coeffs[2] * old_out3;

    out0 -= filter_coeffs[1] * old_out2;
    out1 -= filter_coeffs[1] * old_out3;
    out4 -= filter_coeffs[1] * old_out2;
    out5 -= filter_coeffs[1] * old_out3;

    out0 -= filter_coeffs[0] * old_out3;
    out4 -= filter_coeffs[0] * old_out3;

    val = filter_coeffs[3];
    out0 -= val * old_out0;
    out1 -= val * old_out1;
    out2 -= val * old_out2;
    out3 -= val * old_out3;
    out4 -= val * old_out0;
    out5 -= val * old_out1;
    out6 -= val * old_out2;
    out7 -= val * old_out3;

    for (i = 5; i < filter_length; i += 2) {
        old_out3 = out[-i];
        val = filter_coeffs[i - 1];
        out0 -= val * old_out3;
        out1 -= val * old_out0;
        out2 -= val * old_out1;
        out3 -= val * old_out2;
        out4 -= val * old_out3;
        out5 -= val * old_out0;
        out6 -= val * old_out1;
        out7 -= val * old_out2;

        old_out2 = out[-i - 1];
        val = filter_coeffs[i];
        out0 -= val * old_out2;
        out1 -= val * old_out3;
        out2 -= val * old_out0;
        out3 -= val * old_out1;
        out4 -= val * old_out2;
        out5 -= val * old_out3;
        out6 -= val * old_out0;
        out7 -= val * old_out1;

        float SWAP_tmp = old_out2;
        old_out2 = old_out0;
        old_out0 = SWAP_tmp;
        old_out1 = old_out3;
    }

    tmp0 = out0;
    tmp1 = out1;
    tmp2 = out2;
    out3 -= a * tmp2;
    out2 -= a * tmp1;
    out1 -= a * tmp0;
    out3 -= b * tmp1;
    out2 -= b * tmp0;
    out3 -= c * tmp0;

    tmp3 = out4;
    tmp4 = out5;
    tmp5 = out6;
    out7 -= a * tmp5;
    out6 -= a * tmp4;
    out5 -= a * tmp3;
    out7 -= b * tmp4;
    out6 -= b * tmp3;
    out7 -= c * tmp3;

    out[0] = out0;
    out[1] = out1;
    out[2] = out2;
    out[3] = out3;
    out[4] = out4;
    out[5] = out5;
    out[6] = out6;
    out[7] = out7;

    old_out0 = out4;
    old_out1 = out5;
    old_out2 = out6;
    old_out3 = out7;

    out += 8;
    in += 8;
}
}
