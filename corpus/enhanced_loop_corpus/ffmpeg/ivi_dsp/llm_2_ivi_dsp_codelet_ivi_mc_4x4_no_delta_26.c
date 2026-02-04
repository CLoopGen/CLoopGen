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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with array index reorganization
    // Instead of incrementing buf and ref_buf via pointer arithmetic in the outer loop,
    // we calculate indices directly to access consecutive blocks, improving spatial locality.
    int16_t *b = buf;
    int16_t *r = ref_buf;
    for (i = 0; i < 4; i++) {
        ptrdiff_t offset = i * dpitch;
        ptrdiff_t r_offset = i * pitch;
        for (j = 0; j < 4; j++) {
            b[offset + j] = (r[r_offset + j] + r[r_offset + j + 1]) >> 1;
        }
    }
}
