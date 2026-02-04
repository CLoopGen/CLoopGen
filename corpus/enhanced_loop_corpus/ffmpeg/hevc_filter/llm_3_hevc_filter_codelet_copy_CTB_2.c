#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int width;
extern int height;
extern ptrdiff_t stride_dst;
extern ptrdiff_t stride_src;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access – transpose the iteration order (column-major inner loop)
    // This changes access pattern to stride through memory vertically across rows
    for (j = 0; j < width; j++) {
        for (i = 0; i < height; i++) {
            uint8_t *dst_elem = dst + i * stride_dst + j;
            uint8_t *src_elem = src + i * stride_src + j;
            *dst_elem = *src_elem;
        }
    }
    // Note: dst and src are not advanced per row here; full indexing is used instead.
    // The original pointers remain unchanged after loop, but semantics preserve copy.
}
