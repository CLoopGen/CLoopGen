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
int limit = size >> 1;
for (i = 0; i < limit; i++) {
    float qc = scaled[i] * Q34 * 0.5f;
    int tmp = (int)((qc + rounding) > ((float)maxval) ? ((float)maxval) : (qc + rounding));
    if (is_signed && in[i] < 0.F) {
        tmp = -tmp;
    }
    out[i] = tmp;
}
}
