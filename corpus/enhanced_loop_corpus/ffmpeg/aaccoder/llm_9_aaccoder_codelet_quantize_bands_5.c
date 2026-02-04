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
        int clamped = (int)(adjusted);
        if (clamped > maxval) clamped = maxval;
        else if (clamped < 0) clamped = 0;
        if (is_signed && in[i] < 0.F) {
            out[i] = -clamped;
        } else {
            out[i] = clamped;
        }
    }
}
