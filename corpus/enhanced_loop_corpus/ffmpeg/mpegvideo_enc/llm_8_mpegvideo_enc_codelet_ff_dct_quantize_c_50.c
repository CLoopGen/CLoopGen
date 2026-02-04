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
int temp;
for (i = start_i; i <= last_non_zero; i += 2) {
    j = scantable[i];
    level = block[j] * qmat[j];
    if (((unsigned int)(level + threshold1)) > threshold2) {
        if (level > 0) {
            temp = bias + level;
            level = (temp + (temp >> 4)) >> 20;
            block[j] = level;
        } else {
            temp = bias - level;
            level = (temp + (temp >> 4)) >> 20;
            block[j] = -level;
        }
        max |= level;
    } else {
        block[j] = 0;
    }
    if (i + 1 <= last_non_zero) {
        j = scantable[i + 1];
        level = block[j] * qmat[j];
        if (((unsigned int)(level + threshold1)) > threshold2) {
            if (level > 0) {
                temp = bias + level;
                level = (temp + (temp >> 4)) >> 20;
                block[j] = level;
            } else {
                temp = bias - level;
                level = (temp + (temp >> 4)) >> 20;
                block[j] = -level;
            }
            max |= level;
        } else {
            block[j] = 0;
        }
    }
}
}
