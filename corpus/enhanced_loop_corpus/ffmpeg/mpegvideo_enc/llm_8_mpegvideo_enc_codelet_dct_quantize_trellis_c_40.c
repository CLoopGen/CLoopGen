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
int temp_level;
for (i = start_i; i <= last_non_zero; i += 2) {
    const int j1 = scantable[i];
    int level1 = block[j1] * qmat[j1];
    int skip_branch1 = ((unsigned int)(level1 + threshold1)) > threshold2;
    temp_level = (skip_branch1 ? ((level1 > 0) ? (bias + level1) : (bias - level1)) : 0);
    level1 = (skip_branch1 ? (temp_level >> 21) : 0);
    if (skip_branch1) {
        if (level1 > 0) {
            coeff[0][i] = level1;
            coeff[1][i] = level1 - 1;
        } else {
            coeff[0][i] = -level1;
            coeff[1][i] = -level1 + 1;
        }
        coeff_count[i] = level1 > 2 ? 2 : level1;
        max |= level1;
    } else {
        coeff[0][i] = (level1 >> 31) | 1;
        coeff_count[i] = 1;
    }
    if (i + 1 <= last_non_zero) {
        const int j2 = scantable[i + 1];
        int level2 = block[j2] * qmat[j2];
        int skip_branch2 = ((unsigned int)(level2 + threshold1)) > threshold2;
        temp_level = (skip_branch2 ? ((level2 > 0) ? (bias + level2) : (bias - level2)) : 0);
        level2 = (skip_branch2 ? (temp_level >> 21) : 0);
        if (skip_branch2) {
            if (level2 > 0) {
                coeff[0][i + 1] = level2;
                coeff[1][i + 1] = level2 - 1;
            } else {
                coeff[0][i + 1] = -level2;
                coeff[1][i + 1] = -level2 + 1;
            }
            coeff_count[i + 1] = level2 > 2 ? 2 : level2;
            max |= level2;
        } else {
            coeff[0][i + 1] = (level2 >> 31) | 1;
            coeff_count[i + 1] = 1;
        }
    }
}
}
