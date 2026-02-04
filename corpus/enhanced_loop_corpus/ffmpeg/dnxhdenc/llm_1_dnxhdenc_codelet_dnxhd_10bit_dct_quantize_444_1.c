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
    for (i = 63; i >= start_i; i -= 2) {  // Decrease effective depth by stepping more than 1
        j = scantable[i];
        level = block[j] * qmat[j];
        if (((unsigned int)(level + threshold1)) > threshold2) {
            last_non_zero = i;
            break;
        } else {
            block[j] = 0;
        }
        // Handle the skipped index if within bounds
        if ((i - 1) >= start_i) {
            j = scantable[i - 1];
            level = block[j] * qmat[j];
            if (((unsigned int)(level + threshold1)) > threshold2) {
                last_non_zero = i - 1;
                break;
            } else {
                block[j] = 0;
            }
        }
    }
}
