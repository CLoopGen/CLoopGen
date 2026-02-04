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
int adjusted_level, shift_val = 21;
for (i = start_i; i <= last_non_zero; i++) {
    j = scantable[i];
    level = block[j] << 1; 
    adjusted_level = (level * qmat[j]) >> 1;
    if (((unsigned int)(adjusted_level + threshold1)) > threshold2) {
        if (adjusted_level > 0) {
            adjusted_level = (bias + adjusted_level + (1 << (shift_val - 1))) >> shift_val;
            block[j] = (int16_t)(adjusted_level);
        } else {
            adjusted_level = (bias - adjusted_level + (1 << (shift_val - 1))) >> shift_val;
            block[j] = (int16_t)(-adjusted_level);
        }
        max |= adjusted_level;
    } else {
        block[j] = 0;
    }
}
}
