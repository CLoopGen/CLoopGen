#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dststride;
extern int h;
extern  uint8_t *filter;
extern  uint8_t *cm;
extern int x;
extern int y;
extern uint8_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h; y++) {
    uint8_t *tmp_offset = tmp;
    for (x = 0; x < 8; x++) {
        int index = (filter[2] * tmp_offset[x + 0] - 
                    filter[1] * tmp_offset[x - 8] + 
                    filter[0] * tmp_offset[x - 16] + 
                    filter[3] * tmp_offset[x + 8] - 
                    filter[4] * tmp_offset[x + 16] + 
                    filter[5] * tmp_offset[x + 24] + 64) >> 7;
        dst[x] = cm[index];
    }
    dst += dststride;
    tmp += 8;
}
}
