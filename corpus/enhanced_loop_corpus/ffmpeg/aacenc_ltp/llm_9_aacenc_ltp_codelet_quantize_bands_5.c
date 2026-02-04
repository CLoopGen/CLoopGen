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
int i;
for (i = 0; i < size; i++) {
    float qc = scaled[i] * Q34;
    qc = (qc < 0.F) ? 0.F : qc; // Clamp negative values to zero before rounding
    float adjusted = qc + rounding;
    int clamped_val = (int)(adjusted > (float)maxval ? (float)maxval : adjusted);
    int tmp = is_signed && in[i] < 0.F ? -clamped_val : clamped_val;
    out[i] = tmp;
}
}
