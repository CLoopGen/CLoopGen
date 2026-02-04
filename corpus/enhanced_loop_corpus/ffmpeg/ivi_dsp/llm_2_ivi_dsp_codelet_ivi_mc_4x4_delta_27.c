#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *buf;
extern ptrdiff_t dpitch;
extern  int16_t *ref_buf;
extern ptrdiff_t pitch;
extern int i;
extern int j;
extern  int16_t *wptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with array indexing restructured
    // Instead of incrementing pointers in the outer loop, use base pointer + offset
    int16_t *base_buf = buf;
    int16_t *base_wptr = wptr;
    int16_t *base_ref_buf = ref_buf;
    for (i = 0; i < 4; i++) {
        ptrdiff_t offset = i * dpitch;
        ptrdiff_t offset2 = i * pitch;
        for (j = 0; j < 4; j++) {
            base_buf[offset + j] += ((base_ref_buf[offset2 + j] + base_wptr[offset2 + j]) >> 1);
        }
    }
}
