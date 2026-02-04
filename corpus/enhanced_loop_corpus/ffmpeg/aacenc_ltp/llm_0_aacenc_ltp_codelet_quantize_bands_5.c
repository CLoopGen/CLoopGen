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
        for (int j = 0; j < 2 && (i + j) < size; j++) {
            int idx = i + j;
            float qc = scaled[idx] * Q34;
            int tmp = (int)((qc + rounding) > ((float)maxval) ? ((float)maxval) : (qc + rounding));
            if (is_signed && in[idx] < 0.F) {
                tmp = -tmp;
            }
            out[idx] = tmp;
        }
    }
}
