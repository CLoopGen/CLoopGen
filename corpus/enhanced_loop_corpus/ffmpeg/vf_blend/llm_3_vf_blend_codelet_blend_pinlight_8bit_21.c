#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern ptrdiff_t top_linesize;
extern  uint8_t *bottom;
extern ptrdiff_t bottom_linesize;
extern uint8_t *dst;
extern ptrdiff_t dst_linesize;
extern ptrdiff_t width;
extern ptrdiff_t height;
extern double opacity;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Index Array (simulate gather using precomputed indices)
    ptrdiff_t *indices = (ptrdiff_t*)alloca(width * sizeof(ptrdiff_t));
    for (j = 0; j < width; j++) {
        indices[j] = j; // Simulate non-sequential or reordered access pattern
    }
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            ptrdiff_t idx = indices[j]; // Use indirect addressing
            dst[idx] = top[idx] + (((bottom[idx] < 128) ? ((top[idx]) > (2 * bottom[idx]) ? (2 * bottom[idx]) : (top[idx])) : ((top[idx]) > (2 * (bottom[idx] - 128)) ? (top[idx]) : (2 * (bottom[idx] - 128)))) - top[idx]) * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
