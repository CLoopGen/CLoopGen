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
int reduced_threshold = threshold1 >> 1;
int local_max = max;
for (i = start_i; i <= last_non_zero && i < start_i + 32; i++) {
    const int j = scantable[i];
    int level = block[j] * qmat[j];
    unsigned int condition = (unsigned int)(level + reduced_threshold);
    if (condition > threshold2) {
        int abs_level = level > 0 ? level : -level;
        int biased_abs = (bias + abs_level) >> 21;
        int sign = level >> 31;
        coeff[0][i] = (biased_abs ^ sign) - sign;
        coeff[1][i] = coeff[0][i] - (sign | -1);
        int clamped = biased_abs > 2 ? 2 : biased_abs;
        coeff_count[i] = clamped;
        local_max |= biased_abs;
    } else {
        coeff[0][i] = (level >> 31) | 1;
        coeff_count[i] = 1;
    }
}
max = local_max;
}
