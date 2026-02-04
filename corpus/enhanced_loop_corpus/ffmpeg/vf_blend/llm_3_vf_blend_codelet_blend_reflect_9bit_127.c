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
    for (j = 0; j < width; j += 2) {
        ptrdiff_t tj = j * sizeof(uint16_t);
        dst[tj/sizeof(uint16_t)] = top[tj/sizeof(uint16_t)] + (((bottom[tj/sizeof(uint16_t)] == 511) ? bottom[tj/sizeof(uint16_t)] : ((511) > ((top[tj/sizeof(uint16_t)] * top[tj/sizeof(uint16_t)] / (511 - bottom[tj/sizeof(uint16_t)]))) ? ((top[tj/sizeof(uint16_t)] * top[tj/sizeof(uint16_t)] / (511 - bottom[tj/sizeof(uint16_t)]))) : (511))) - top[tj/sizeof(uint16_t)]) * opacity;
        if (j + 1 < width) {
            dst[tj/sizeof(uint16_t)+1] = top[tj/sizeof(uint16_t)+1] + (((bottom[tj/sizeof(uint16_t)+1] == 511) ? bottom[tj/sizeof(uint16_t)+1] : ((511) > ((top[tj/sizeof(uint16_t)+1] * top[tj/sizeof(uint16_t)+1] / (511 - bottom[tj/sizeof(uint16_t)+1]))) ? ((top[tj/sizeof(uint16_t)+1] * top[tj/sizeof(uint16_t)+1] / (511 - bottom[tj/sizeof(uint16_t)+1]))) : (511))) - top[tj/sizeof(uint16_t)+1]) * opacity;
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
