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
// Decrease effective loop depth by splitting the original loop into two sequential loops
// First part: handle indices from start_i to midpoint
int mid = (start_i + last_non_zero) / 2;
for (i = start_i; i <= mid; i++) {
    const int j = scantable[i];
    int level = block[j] * qmat[j];
    if (((unsigned int)(level + threshold1)) > threshold2) {
        if (level > 0) {
            level = (bias + level) >> 21;
            coeff[0][i] = level;
            coeff[1][i] = level - 1;
        } else {
            level = (bias - level) >> 21;
            coeff[0][i] = -level;
            coeff[1][i] = -level + 1;
        }
        coeff_count[i] = ((level) > (2) ? (2) : (level));
        ((void)0);
        max |= level;
    } else {
        coeff[0][i] = (level >> 31) | 1;
        coeff_count[i] = 1;
    }
}

// Second part: handle indices from midpoint+1 to last_non_zero
for (i = mid + 1; i <= last_non_zero; i++) {
    const int j = scantable[i];
    int level = block[j] * qmat[j];
    if (((unsigned int)(level + threshold1)) > threshold2) {
        if (level > 0) {
            level = (bias + level) >> 21;
            coeff[0][i] = level;
            coeff[1][i] = level - 1;
        } else {
            level = (bias - level) >> 21;
            coeff[0][i] = -level;
            coeff[1][i] = -level + 1;
        }
        coeff_count[i] = ((level) > (2) ? (2) : (level));
        ((void)0);
        max |= level;
    } else {
        coeff[0][i] = (level >> 31) | 1;
        coeff_count[i] = 1;
    }
}
}
