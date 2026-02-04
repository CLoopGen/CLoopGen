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
    uint16_t temp;
    for (y = 0; y < h; y++, dst += dst_linesize, src += 2) {
        for (x = 0; x < w; x++) {
            temp = *((uint16_t *)(src + x * src_linesize));
            *((uint16_t *)(dst + 2 * x)) = temp;
        }
    }
}
