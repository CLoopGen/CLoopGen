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
    ptrdiff_t offset;
    uint16_t combined, clamped_diff;
    for (i = 0; i < height; i++) {
        offset = i * dst_linesize;
        for (j = 0; j < width; j++) {
            combined = top[j] + bottom[j];
            clamped_diff = (511 - combined) >= 0 ? (511 - combined) : (combined - 511);
            dst[offset + j] = top[j] + (clamped_diff - top[j]) * opacity;
        }
    }
    // Eliminated per-row pointer arithmetic to remove WAW and WAR hazards
    // by computing destination index directly (introducing loop-invariant offset).
}
