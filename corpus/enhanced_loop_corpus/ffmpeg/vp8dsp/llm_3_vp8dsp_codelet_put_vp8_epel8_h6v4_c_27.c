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
    uint8_t *tmp_offset = tmp;
    uint8_t *dst_offset = dst;
    for (y = 0; y < h; y++) {
        for (x = 0; x < 8; x++) {
            ptrdiff_t idx = x;
            dst_offset[idx] = cm[(filter[2] * tmp_offset[x + 0 * 8] - filter[1] * tmp_offset[x - 1 * 8] + filter[3] * tmp_offset[x + 1 * 8] - filter[4] * tmp_offset[x + 2 * 8] + 64) >> 7];
        }
        dst_offset += dststride;
        tmp_offset += 8;
    }
}
