#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t src_linesize;
extern uint8_t *dst;
extern ptrdiff_t dst_linesize;
extern int w;
extern int h;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < h; y++) {
        uint8_t *src_line = src + y * src_linesize;
        uint8_t *dst_line = dst + y * dst_linesize;
        for (x = 0; x < w; x++) {
            *((uint64_t *)(dst_line + 8 * x)) = *((uint64_t *)(src_line + x * src_linesize));
        }
    }
}
