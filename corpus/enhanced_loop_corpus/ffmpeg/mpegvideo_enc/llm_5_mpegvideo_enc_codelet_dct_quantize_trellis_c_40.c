#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern  int *qmat;
extern  uint8_t *scantable;
extern int max;
extern unsigned int threshold1;
extern unsigned int threshold2;
extern int bias;
extern int coeff[2][64];
extern int coeff_count[64];
extern int start_i;
extern int last_non_zero;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = start_i; i <= last_non_zero; i++) {
    const int j = scantable[i];
    int level = block[j] * qmat[j];
    unsigned int cond = (unsigned int)(level + threshold1) <= threshold2;
    int abs_level = level >= 0 ? level : -level;
    int sign_bit = level >> 31;
    int biased_abs = (bias + abs_level) >> 21;
    int clamped_coeff = biased_abs < 2 ? biased_abs : 2;

    coeff_count[i] = cond ? 1 : clamped_coeff;
    max |= cond ? 0 : biased_abs;

    if (!cond) {
        coeff[0][i] = sign_bit ? -biased_abs : biased_abs;
        coeff[1][i] = sign_bit ? -biased_abs + 1 : biased_abs - 1;
    } else {
        coeff[0][i] = sign_bit | 1;
    }
}
}
