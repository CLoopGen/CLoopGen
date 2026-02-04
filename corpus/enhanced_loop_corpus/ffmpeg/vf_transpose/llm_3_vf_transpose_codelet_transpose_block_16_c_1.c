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
    // Variant 2: Strided Memory Access with Reverse Traversal (reverse both dimensions, strided write)
    for (y = h - 1; y >= 0; y--) {
        const uint8_t *s = src + 2 * y;
        uint8_t *d = dst + y * dst_linesize;
        for (x = w - 1; x >= 0; x--) {
            *((uint16_t *)(d + 2 * x)) = *((uint16_t *)(s + x * src_linesize));
        }
    }
}
