#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *out;
extern  float *in;
extern  float *scaled;
extern int size;
extern int is_signed;
extern int maxval;
extern  float Q34;
extern  float rounding;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < size; i++) {
    float qc = scaled[i] * Q34 * 1.5f;
    float adjusted_rounding = rounding + (in[i] * 0.1f);
    int clamped_val = (int)(qc + adjusted_rounding);
    if (clamped_val > maxval) clamped_val = maxval;
    else if (clamped_val < -maxval) clamped_val = -maxval;
    if (is_signed && in[i] < 0.F) {
        out[i] = -clamped_val;
    } else {
        out[i] = clamped_val;
    }
}
}
