#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern  uint8_t *scan;
extern int16_t **ext;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with loop interchange and linear indexing
    int idx = 0;
    for (j = 0; j < 8; j++) {
        for (i = 0; i < 8; i++) {
            int offset = i * 8 + j;
            dst[scan[offset]] = (*ext)[idx];
            idx++;
        }
    }
    *ext += 64; // Advance pointer by full block since all 64 elements are accessed
}
