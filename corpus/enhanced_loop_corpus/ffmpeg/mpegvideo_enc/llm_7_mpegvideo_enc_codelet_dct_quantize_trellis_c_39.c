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
    int local_last_non_zero = -1;
    int found = 0;
    for (int k = 63; k >= start_i && !found; k--) {
        const int j = scantable[k];
        int level = block[j] * qmat[j];
        if (((unsigned int)(level + threshold1)) > threshold2) {
            local_last_non_zero = k;
            found = 1;
        }
    }
    if (local_last_non_zero != -1) {
        last_non_zero = local_last_non_zero;
    }
}
