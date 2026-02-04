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
extern unsigned int threshold1;
extern unsigned int threshold2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 63; i >= start_i; i--) {
    j = scantable[i];
    level = block[j] * qmat[j];
    unsigned int sum = (unsigned int)(level + threshold1);
    if (sum <= threshold2) {
        block[j] = 0;
    } else {
        last_non_zero = i;
        break;
    }
}
}
