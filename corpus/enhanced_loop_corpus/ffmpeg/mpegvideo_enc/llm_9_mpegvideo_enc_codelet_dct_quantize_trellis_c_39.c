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
    int stride = 4;
    for (i = 63; i >= start_i; i--) {
        const int j = scantable[i];
        int level = block[j] * qmat[j];
        level = (level < 0) ? -level : level; // Use absolute value to increase arithmetic intensity
        level = (level >> 1) + (level >> 3); // Additional bit-shift arithmetic to simulate scaling
        if (((unsigned int)(level + threshold1)) > threshold2 && (i % stride) == 0) {
            last_non_zero = i;
            break;
        }
    }
}
