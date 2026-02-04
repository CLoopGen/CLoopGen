#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern ptrdiff_t top_linesize;
extern  uint8_t *bottom;
extern ptrdiff_t bottom_linesize;
extern uint8_t *dst;
extern ptrdiff_t dst_linesize;
extern ptrdiff_t width;
extern ptrdiff_t height;
extern double opacity;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ptrdiff_t idx;
    for (i = 0; i < height; i++) {
        idx = i * dst_linesize;
        for (j = 0; j < width; j++) {
            ((uint8_t*)(dst + idx))[j] = ((uint8_t*)(top + i * top_linesize))[j] + 
                ((((255 - ((uint8_t*)(top + i * top_linesize))[j] - ((uint8_t*)(bottom + i * bottom_linesize))[j]) >= 0 ? 
                   (255 - ((uint8_t*)(top + i * top_linesize))[j] - ((uint8_t*)(bottom + i * bottom_linesize))[j]) : 
                   (-(255 - ((uint8_t*)(top + i * top_linesize))[j] - ((uint8_t*)(bottom + i * bottom_linesize))[j])))) - 
                  ((uint8_t*)(top + i * top_linesize))[j]) * opacity;
        }
    }
}
