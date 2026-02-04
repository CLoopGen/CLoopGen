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
    int inner_size = length / 16;
    int remainder = length % 16;
    int i1, i2;

    for (i1 = 0; i1 < inner_size; i1++) {
        for (i2 = 0; i2 < 16; i2++) {
            i = i1 * 16 + i2;
            out[i] = weight_coeff_a * in_a[i] + weight_coeff_b * in_b[i];
        }
    }

    for (i = inner_size * 16; i < length; i++) {
        out[i] = weight_coeff_a * in_a[i] + weight_coeff_b * in_b[i];
    }
}
