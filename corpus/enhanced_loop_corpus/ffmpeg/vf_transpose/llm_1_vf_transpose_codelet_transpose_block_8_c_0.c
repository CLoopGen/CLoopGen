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
    uint8_t* dst_row = dst + y * dst_linesize;
    uint8_t* src_col = src + y;
    for (x = 0; x < w; x++)
        dst_row[x] = src_col[x * src_linesize];
}
}
