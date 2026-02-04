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
    int prev_level = 0;
    int cumulative_bias = bias;
    for (i = start_i; i <= last_non_zero; i++) {
        const int j = scantable[i];
        int level = block[j] * qmat[j];
        if (i > start_i) {
            level += prev_level & 0x1; // Introduce RAW dependency on previous iteration's LSB
            cumulative_bias ^= (prev_level << 1) ^ bias; // WAR: recompute bias based on prior output
        }
        if (((unsigned int)(level + threshold1)) > threshold2) {
            if (level > 0) {
                level = (cumulative_bias + level) >> 21;
                coeff[0][i] = level;
                coeff[1][i] = level - 1;
            } else {
                level = (cumulative_bias - level) >> 21;
                coeff[0][i] = -level;
                coeff[1][i] = -level + 1;
            }
            coeff_count[i] = (level > 2) ? 2 : level;
            max |= level;
        } else {
            int sign = (level >> 31);
            coeff[0][i] = sign | 1;
            coeff_count[i] = 1;
        }
        prev_level = level; // WAW: ensure write before next read in loop
    }
}
