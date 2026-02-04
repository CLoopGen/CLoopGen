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
    unsigned int threshold_check = (unsigned int)(level + threshold1) > threshold2;
    int sign = level >> 31;
    level = (level ^ sign) - sign; // Absolute value without branching
    if (threshold_check) {
        int biased_level = (bias + level) >> 21;
        coeff[0][i] = (sign ? -biased_level : biased_level);
        coeff[1][i] = (sign ? -biased_level + 1 : biased_level - 1);
        coeff_count[i] = (biased_level > 2) ? 2 : biased_level;
        max |= biased_level;
    } else {
        coeff[0][i] = sign | 1;
        coeff_count[i] = 1;
    }
}
}
