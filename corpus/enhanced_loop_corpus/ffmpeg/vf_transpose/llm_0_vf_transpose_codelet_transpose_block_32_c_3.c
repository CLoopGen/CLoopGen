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
for (y = 0; y < h; y++ , dst += dst_linesize , src += 4) {
    x = 0;
    if (w > 0) {
        *((uint32_t *)(dst + 4 * x)) = *((uint32_t *)(src + x * src_linesize));
        for (x = 1; x < w; x++)
            *((uint32_t *)(dst + 4 * x)) = *((uint32_t *)(src + x * src_linesize));
    }
}
}
