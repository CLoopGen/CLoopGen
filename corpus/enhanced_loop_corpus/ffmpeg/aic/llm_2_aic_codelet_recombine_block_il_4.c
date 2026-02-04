#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern  uint8_t *scan;
extern int16_t **base;
extern int16_t **ext;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with precomputed indices
    int16_t *base_ptr = *base;
    int16_t *ext_ptr = *ext;
    for (i = 0; i < 8; i++) {
        int offset = i * 8;
        uint8_t *scan_offset = &scan[offset];
        for (j = 0; j < 4; j++) {
            dst[scan_offset[j]] = base_ptr[j];
        }
        for (j = 0; j < 4; j++) {
            dst[scan_offset[j + 4]] = ext_ptr[j];
        }
        base_ptr += 4;
        ext_ptr += 4;
    }
    *base = base_ptr;
    *ext = ext_ptr;
}
