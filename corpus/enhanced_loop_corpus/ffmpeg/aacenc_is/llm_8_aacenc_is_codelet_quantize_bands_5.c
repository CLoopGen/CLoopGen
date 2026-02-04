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
for (i = 0; i < size; i += 2) {
    float qc1 = scaled[i] * Q34;
    int tmp1 = (int)((qc1 + rounding) > ((float)maxval) ? ((float)maxval) : (qc1 + rounding));
    if (is_signed && in[i] < 0.F) {
        tmp1 = -tmp1;
    }
    out[i] = tmp1;

    if (i + 1 < size) {
        float qc2 = scaled[i+1] * Q34;
        int tmp2 = (int)((qc2 + rounding) > ((float)maxval) ? ((float)maxval) : (qc2 + rounding));
        if (is_signed && in[i+1] < 0.F) {
            tmp2 = -tmp2;
        }
        out[i+1] = tmp2;
    }
}
}
