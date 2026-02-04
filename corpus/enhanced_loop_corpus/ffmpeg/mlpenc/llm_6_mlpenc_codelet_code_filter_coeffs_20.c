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
    int temp_min = min;
    int temp_max = max;
    int temp_mask = coeff_mask;
    for (order = 0; order < fp->order; order++) {
        int coeff = fcoeff[order];
        temp_min = (coeff < temp_min) ? coeff : temp_min;
        temp_max = (coeff > temp_max) ? coeff : temp_max;
        temp_mask |= coeff;
    }
    min = temp_min;
    max = temp_max;
    coeff_mask = temp_mask;
}
