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
    int y, x;
    uint8_t *tmp_offset = tmp;
    for (y = 0; y < h; y++) {
        for (x = 15; x >= 0; x--) {  // Reverse loop order (introduces WAR dependency on x)
            int index = (filter[2] * tmp_offset[x + 0 * 16] - 
                         filter[1] * tmp_offset[x - 1 * 16] + 
                         filter[0] * tmp_offset[x - 2 * 16] + 
                         filter[3] * tmp_offset[x + 1 * 16] - 
                         filter[4] * tmp_offset[x + 2 * 16] + 
                         filter[5] * tmp_offset[x + 3 * 16] + 64) >> 7;
            dst[x] = cm[index];  // WAW removed by direct assignment, RAW preserved via cm and filter
        }
        dst += dststride;
        tmp_offset += 16;
    }
    tmp = tmp_offset;  // Update original tmp to reflect advancement (adds loop-carried WAW on tmp)
}
