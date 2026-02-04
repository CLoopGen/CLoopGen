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
    int local_level;
    int temp_j;
    for (i = 63; i >= start_i; i--) {
        temp_j = scantable[i];
        local_level = block[temp_j] * qmat[temp_j];
        if (((unsigned int)(local_level + threshold1)) > threshold2) {
            last_non_zero = i;
            block[temp_j] = (int16_t)local_level; // Re-assign to maintain consistency
            break;
        } else {
            block[temp_j] = 0;
        }
    }
}
