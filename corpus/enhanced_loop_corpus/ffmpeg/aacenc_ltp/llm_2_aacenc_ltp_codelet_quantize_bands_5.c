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
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < size; i += 2) {
        float qc = scaled[i] * Q34;
        int tmp = (int)((qc + rounding) > ((float)maxval) ? ((float)maxval) : (qc + rounding));
        if (is_signed && in[i] < 0.F) {
            tmp = -tmp;
        }
        out[i] = tmp;

        // Process next element if within bounds
        if (i + 1 < size) {
            float qc_next = scaled[i + 1] * Q34;
            int tmp_next = (int)((qc_next + rounding) > ((float)maxval) ? ((float)maxval) : (qc_next + rounding));
            if (is_signed && in[i + 1] < 0.F) {
                tmp_next = -tmp_next;
            }
            out[i + 1] = tmp_next;
        }
    }
}
