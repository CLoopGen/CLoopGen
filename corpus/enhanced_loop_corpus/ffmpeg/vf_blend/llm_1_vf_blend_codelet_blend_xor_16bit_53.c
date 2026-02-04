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
for (i = 0; i < height * width; i++) {
    int j = i % width;
    int current_row = i / width;
    if (j == 0 && current_row > 0) {
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
    dst[j] = top[j] + ((top[j] ^ bottom[j]) - top[j]) * opacity;
}
// Restore pointers after flat loop execution
dst += dst_linesize;
top += top_linesize;
bottom += bottom_linesize;
}
