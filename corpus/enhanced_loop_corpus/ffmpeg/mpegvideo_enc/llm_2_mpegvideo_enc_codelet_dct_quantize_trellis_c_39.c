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
    // Variant 1: Consecutive Memory Access with Reversed Scanning
    // Instead of using indirect access via scantable[i], we assume a reordered block
    // where coefficients are already arranged in zigzag order, allowing direct consecutive access.
    // We simulate this by treating 'block' as if it's been pre-reordered according to the scan pattern.
    for (i = 63; i >= start_i; i--) {
        int level = block[i] * qmat[i];  // Direct consecutive access instead of indirect
        if (((unsigned int)(level + threshold1)) > threshold2) {
            last_non_zero = i;
            break;
        }
    }
}
