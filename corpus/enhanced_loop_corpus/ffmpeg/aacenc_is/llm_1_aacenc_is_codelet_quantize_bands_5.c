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
    int chunk_size = 16;
    int outer_i;
    for (outer_i = 0; outer_i < size; outer_i += chunk_size) {
        int inner_i;
        for (inner_i = outer_i; inner_i < size && inner_i < outer_i + chunk_size; inner_i++) {
            float qc = scaled[inner_i] * Q34;
            int tmp = (int)((qc + rounding) > ((float)maxval) ? ((float)maxval) : (qc + rounding));
            if (is_signed && in[inner_i] < 0.F) {
                tmp = -tmp;
            }
            out[inner_i] = tmp;
        }
    }
}
