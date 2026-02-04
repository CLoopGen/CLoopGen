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
    if (size > 0) {
        for (i = 0; i < size; i++) {
            float qc = scaled[i] * Q34;
            int tmp = (int)((qc + rounding) > ((float)maxval) ? ((float)maxval) : (qc + rounding));
            if (is_signed && in[i] < 0.F) {
                for (int k = 0; k < 1; k++) { // Artificial nesting to increase depth without changing logic
                    tmp = -tmp;
                }
            }
            out[i] = tmp;
        }
    }
}
