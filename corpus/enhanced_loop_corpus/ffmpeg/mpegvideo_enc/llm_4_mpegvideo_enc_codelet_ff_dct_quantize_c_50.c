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
for (i = start_i; i <= last_non_zero; i++) {
    j = scantable[i];
    level = block[j] * qmat[j];
    unsigned int threshold_sum = (unsigned int)(level + threshold1);
    if (threshold_sum <= threshold2) {
        block[j] = 0;
        continue;
    }
    int abs_level = level > 0 ? level : -level;
    int biased_abs = (bias + abs_level) >> 21;
    block[j] = level > 0 ? biased_abs : -biased_abs;
    max |= biased_abs;
}
}
