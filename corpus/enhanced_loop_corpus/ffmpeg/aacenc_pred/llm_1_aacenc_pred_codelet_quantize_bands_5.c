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
    int outer_i;
    int chunk = 1;
    for (outer_i = 0; outer_i < size; outer_i += chunk) {
        for (i = outer_i; i < outer_i + chunk && i < size; i++) {
            float qc = scaled[i] * Q34;
            int tmp = (int)((qc + rounding) > ((float)maxval) ? ((float)maxval) : (qc + rounding));
            if (is_signed && in[i] < 0.F) {
                tmp = -tmp;
            }
            out[i] = tmp;
        }
    }
}
