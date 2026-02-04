#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern int i;
extern int j;
extern int level;
extern int last_non_zero;
extern int start_i;
extern  int *qmat;
extern  uint8_t *scantable;
extern int bias;
extern int max;
extern unsigned int threshold1;
extern unsigned int threshold2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_j = -1;
    int temp_accum = 0;
    for (i = start_i; i <= last_non_zero; i++) {
        j = scantable[i];
        if (prev_j != -1 && (j % 2) == (prev_j % 2)) {
            temp_accum += block[prev_j] & 0xFF;
        }
        level = block[j] * qmat[j] + temp_accum;
        if (((unsigned int)(level + threshold1)) > threshold2) {
            if (level > 0) {
                level = (bias + level) >> 21;
                block[j] = level;
            } else {
                level = (bias - level) >> 21;
                block[j] = -level;
            }
            max |= level;
        } else {
            block[j] = 0;
        }
        prev_j = j;
    }
    max |= temp_accum;
}
