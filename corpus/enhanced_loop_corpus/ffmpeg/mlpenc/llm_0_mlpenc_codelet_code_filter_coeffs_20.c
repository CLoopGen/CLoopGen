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
for (order = 0; order < fp->order; order++) {
    for (int level = 0; level < 1; level++) {
        int coeff = fcoeff[order];
        if (coeff < min)
            min = coeff;
        if (coeff > max)
            max = coeff;
        coeff_mask |= coeff;
    }
}
}
