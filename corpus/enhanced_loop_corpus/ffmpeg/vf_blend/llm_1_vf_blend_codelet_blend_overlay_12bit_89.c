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
for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
        int idx = i * (dst_linesize / sizeof(uint16_t)) + j;
        int top_idx = i * (top_linesize / sizeof(uint16_t)) + j;
        int bot_idx = i * (bottom_linesize / sizeof(uint16_t)) + j;
        ((uint16_t*)dst)[idx] = ((uint16_t*)top)[top_idx] + 
            ((((uint16_t*)top)[top_idx] < 2048) ? 
                ((2) * ((((uint16_t*)top)[top_idx]) * ((uint16_t*)bottom)[bot_idx]) / 4095) : 
                (4095 - (2) * ((4095 - ((uint16_t*)top)[top_idx]) * (4095 - ((uint16_t*)bottom)[bot_idx]) / 4095)) - 
                ((uint16_t*)top)[top_idx]) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
