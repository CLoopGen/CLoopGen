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
    ptrdiff_t offset = 0;
    for (y = 0; y < h; y++) {
        for (x = 0; x < 4; x++) {
            ptrdiff_t idx_base = offset + x * 4;
            dst[x] = cm[(filter[2] * tmp[idx_base + 0] - 
                         filter[1] * tmp[idx_base - 4] + 
                         filter[3] * tmp[idx_base + 4] - 
                         filter[4] * tmp[idx_base + 8] + 64) >> 7];
        }
        dst += dststride;
        offset += 4;
    }
}
