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
for (n = 0; n <= buffer_length - 4; n += 4) {
    float tmp0, tmp1, tmp2;
    float val;
    out0 = in[0];
    out1 = in[1];
    out2 = in[2];
    out3 = in[3];
    out0 -= filter_coeffs[2] * old_out1;
    out1 -= filter_coeffs[2] * old_out2;
    out2 -= filter_coeffs[2] * old_out3;
    out0 -= filter_coeffs[1] * old_out2;
    out1 -= filter_coeffs[1] * old_out3;
    out0 -= filter_coeffs[0] * old_out3;
    val = filter_coeffs[3];
    out0 -= val * old_out0;
    out1 -= val * old_out1;
    out2 -= val * old_out2;
    out3 -= val * old_out3;
    for (i = 5; i < filter_length; i += 2) {
        old_out3 = out[-i];
        val = filter_coeffs[i - 1];
        out0 -= val * old_out3;
        out1 -= val * old_out0;
        out2 -= val * old_out1;
        out3 -= val * old_out2;
        old_out2 = out[-i - 1];
        val = filter_coeffs[i];
        out0 -= val * old_out2;
        out1 -= val * old_out3;
        out2 -= val * old_out0;
        out3 -= val * old_out1;
        do {
            float SWAP_tmp = old_out2;
            old_out2 = old_out0;
            old_out0 = SWAP_tmp;
        } while (0);
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
    out[0] = out0;
    out[1] = out1;
    out[2] = out2;
    out[3] = out3;
    old_out0 = out0;
    old_out1 = out1;
    old_out2 = out2;
    old_out3 = out3;
    out += 4;
    in += 4;
}

}
