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
    int temp_coeff0[64] = {0};
    int temp_coeff1[64] = {0};
    int temp_count[64] = {0};
    int local_max = max;
    for (i = start_i; i <= last_non_zero; i++) {
        const int j = scantable[i];
        int level = block[j] * qmat[j];
        if (((unsigned int)(level + threshold1)) > threshold2) {
            if (level > 0) {
                level = (bias + level) >> 21;
                temp_coeff0[i] = level;
                temp_coeff1[i] = level - 1;
            } else {
                level = (bias - level) >> 21;
                temp_coeff0[i] = -level;
                temp_coeff1[i] = -level + 1;
            }
            temp_count[i] = (level > 2) ? 2 : level;
            local_max |= level;
        } else {
            temp_coeff0[i] = (level >> 31) | 1;
            temp_count[i] = 1;
        }
    }
    for (i = start_i; i <= last_non_zero; i++) {
        coeff[0][i] = temp_coeff0[i];
        coeff[1][i] = temp_coeff1[i];
        coeff_count[i] = temp_count[i];
    }
    max = local_max;
}
