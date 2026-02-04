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
    // Variant 2: Strided memory access pattern
    // Instead of grouped 4-element chunks, write values with a fixed stride
    // across the destination array, simulating a transposed or interleaved layout.
    // We now access dst with a stride of 2, scattering the written values.

    int base_idx, ext_idx;
    for (i = 0; i < 4; i++) {
        base_idx = i * 2;  // Stride of 2 for base data
        ext_idx = i * 2 + 1;  // Stride of 2 for ext data, offset by 1
        for (j = 0; j < 4; j++) {
            dst[scan[base_idx * 4 + j]] = (*base)[j];  // Indirect but strided pattern
        }
        for (j = 0; j < 4; j++) {
            dst[scan[ext_idx * 4 + j]] = (*ext)[j];    // Same for ext
        }
        *base += 4;
        *ext += 4;
    }
}
