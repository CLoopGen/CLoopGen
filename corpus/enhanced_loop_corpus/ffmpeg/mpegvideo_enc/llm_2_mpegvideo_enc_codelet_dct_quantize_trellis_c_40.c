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



void loop() {
    // Variant 1: Consecutive Memory Access Pattern
    // Reorder the loop to access arrays in a more sequential manner by precomputing indices.
    // This variant assumes that `scantable` values are unique and within valid bounds.

    int temp_scantable[64];
    int temp_order[64];
    int count = 0;

    for (int idx = start_i; idx <= last_non_zero; idx++) {
        temp_scantable[count] = scantable[idx];
        temp_order[count] = idx;
        count++;
    }

    for (int k = 0; k < count; k++) {
        const int i = temp_order[k];
        const int j = temp_scantable[k];
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
            coeff_count[i] = (level > 2) ? 2 : level;
            max |= level;
        } else {
            coeff[0][i] = (level >> 31) | 1;
            coeff_count[i] = 1;
        }
    }
}
