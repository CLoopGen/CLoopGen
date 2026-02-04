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
    float qc = scaled[i] * Q34;
    float adjusted = qc + rounding;
    int tmp;

    if (adjusted > (float)maxval) {
        tmp = maxval;
    } else {
        tmp = (int)adjusted;
    }

    tmp = is_signed && (in[i] < 0.F) ? -tmp : tmp;

    out[i] = tmp;
}
}
