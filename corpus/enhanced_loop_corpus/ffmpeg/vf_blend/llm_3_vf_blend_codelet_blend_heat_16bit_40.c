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
    // Variant 2: Indirect Memory Access via Index Array (simulate gather pattern)
    ptrdiff_t *index_map = (ptrdiff_t*)malloc(width * sizeof(ptrdiff_t));
    if (!index_map) exit(1);
    // Create indirect access pattern: reverse order
    for (j = 0; j < width; j++) {
        index_map[j] = width - 1 - j;
    }

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            ptrdiff_t idx = index_map[j]; // Indirect access index
            dst[idx] = top[idx] + (((top[idx] == 0) ? 0 : 65535 - ((((65535 - bottom[idx]) * (65535 - bottom[idx])) / top[idx]) > (65535) ? (65535) : (((65535 - bottom[idx]) * (65535 - bottom[idx])) / top[idx]))) - top[idx]) * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }

    free(index_map);
}
