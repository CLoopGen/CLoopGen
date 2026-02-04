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



void loop() {
    for (i = 63; i >= start_i; i -= 2) {
        const int j1 = scantable[i];
        const int j2 = (i - 1 >= start_i) ? scantable[i - 1] : j1;
        int level1 = block[j1] * qmat[j1];
        int level2 = block[j2] * qmat[j2];
        unsigned int cond1 = (unsigned int)(level1 + threshold1) > threshold2;
        unsigned int cond2 = (unsigned int)(level2 + threshold1) > threshold2;
        if (cond1 || cond2) {
            last_non_zero = cond1 ? i : i - 1;
            break;
        }
    }
}
