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
    // Variant 2: Consecutive Reverse Memory Access Pattern
    // Traverse each row from the end to the beginning to reverse access order.
    // This maintains consecutive access but changes spatial locality and direction.
    for (i = 0; i < height; i++) {
        for (j = width - 1; j >= 0; j--) {
            dst[j] = top[j] + ((top[j] ^ bottom[j]) - top[j]) * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
