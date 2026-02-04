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
for (y = 0; y < h; y++ , dst += dst_linesize , src += 8)
    for (x = 0; x < w; x++)
        *((uint64_t *)(dst + 8 * x)) = *((uint64_t *)(src + x * src_linesize));

}
