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
    for (i = 0; i < length; i++) {
        if (in_a[i] >= 0.0f) {
            out[i] = weight_coeff_a * in_a[i];
        } else {
            out[i] = weight_coeff_b * in_b[i];
        }
    }
}
