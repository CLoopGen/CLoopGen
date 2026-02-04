#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t top_linesize;
extern ptrdiff_t bottom_linesize;
extern ptrdiff_t dst_linesize;
extern ptrdiff_t width;
extern ptrdiff_t height;
extern  uint16_t *top;
extern  uint16_t *bottom;
extern uint16_t *dst;
extern double opacity;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing consecutive elements (j), we access with a stride of 2,
    // processing even indices first, then handling odd indices in a second pass.
    // This changes spatial locality and may affect cache behavior.

    // First pass: process even indices
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j += 2) {
            dst[j] = top[j] + ((((top[j] - bottom[j]) >= 0 ? (top[j] - bottom[j]) : (-(top[j] - bottom[j])))) - top[j]) * opacity;
        }
        for (j = 1; j < width; j += 2) {
            dst[j] = top[j] + ((((top[j] - bottom[j]) >= 0 ? (top[j] - bottom[j]) : (-(top[j] - bottom[j])))) - top[j]) * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
