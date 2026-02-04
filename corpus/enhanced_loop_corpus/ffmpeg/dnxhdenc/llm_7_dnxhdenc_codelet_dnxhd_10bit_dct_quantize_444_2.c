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
    int local_max = max;
    int temp_j, temp_level;
    for (i = start_i; i <= last_non_zero; i++) {
        temp_j = scantable[i];
        temp_level = block[temp_j] * qmat[temp_j];
        if (((unsigned int)(temp_level + threshold1)) > threshold2) {
            if (temp_level > 0) {
                temp_level = (bias + temp_level) >> 16;
                block[temp_j] = temp_level;
            } else {
                temp_level = (bias - temp_level) >> 16;
                block[temp_j] = -temp_level;
            }
            local_max |= temp_level;
        } else {
            block[temp_j] = 0;
        }
    }
    max = local_max;
}
