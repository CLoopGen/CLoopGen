#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct FilterParams {
    uint8_t order;
    uint8_t shift;
    int32_t state[8];
    int coeff_bits;
    int coeff_shift;
} FilterParams;

extern FilterParams *fp;
extern int32_t *fcoeff;
extern int min;
extern int max;
extern int coeff_mask;
extern int order;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 2;
    for (order = 0; order < fp->order; order += stride) {
        int coeff = fcoeff[order];
        min = (coeff < min) ? coeff : min;
        max = (coeff > max) ? coeff : max;
        coeff_mask |= coeff;
        if (order + 1 < fp->order) {
            int next_coeff = fcoeff[order + 1];
            min = (next_coeff < min) ? next_coeff : min;
            max = (next_coeff > max) ? next_coeff : max;
            coeff_mask |= next_coeff;
        }
    }
}
