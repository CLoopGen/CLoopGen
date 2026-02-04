#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *buf;
extern ptrdiff_t pitch;
extern int16_t tmp[64];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by flattening the 2D-like access into a linear stride
    int16_t *buf_ptr = buf;
    for (i = 0; i < 8; i++) {
        int base_idx = i * 8;
        for (j = 0; j < 8; j++) {
            *(buf_ptr + j) += tmp[base_idx + j] >> 1;
        }
        buf_ptr += pitch;
    }
}
