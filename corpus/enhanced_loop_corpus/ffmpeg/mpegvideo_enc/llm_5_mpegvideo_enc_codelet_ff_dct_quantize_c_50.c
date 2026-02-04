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
    unsigned int condition = (unsigned int)(level + threshold1) > threshold2;
    level = condition ? ((level > 0) ? ((bias + level) >> 21) : ((bias - level) >> 21)) : 0;
    block[j] = condition ? (level > 0 ? level : -level) : 0;
    if (condition) {
        max |= level;
    }
}
}
