#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *out;
extern  float *in_a;
extern  float *in_b;
extern float weight_coeff_a;
extern float weight_coeff_b;
extern int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    float wc_a_sq = weight_coeff_a * weight_coeff_a;
    float wc_b_sq = weight_coeff_b * weight_coeff_b;
    for (i = 0; i < length; i++) {
        float a_val = in_a[i];
        float b_val = in_b[i];
        out[i] = wc_a_sq * a_val * a_val + wc_b_sq * b_val * b_val + 2.0f * weight_coeff_a * weight_coeff_b * a_val * b_val;
    }
}
