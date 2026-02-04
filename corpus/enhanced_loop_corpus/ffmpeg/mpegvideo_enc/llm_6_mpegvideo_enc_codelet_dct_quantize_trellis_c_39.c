#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern  int *qmat;
extern  uint8_t *scantable;
extern unsigned int threshold1;
extern unsigned int threshold2;
extern int start_i;
extern int last_non_zero;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_last_non_zero = last_non_zero;
    for (i = 63; i >= start_i; i--) {
        const int j = scantable[i];
        int level = block[j] * qmat[j];
        if (((unsigned int)(level + threshold1)) > threshold2) {
            temp_last_non_zero = i;
            break;
        }
    }
    last_non_zero = temp_last_non_zero;
}
