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
        uint8_t temp_vals[8];
        for (x = 0; x < 8; x++) {
            int index = x * 8;
            temp_vals[x] = cm[(filter[2] * tmp[index + 0] - filter[1] * tmp[index - 8] + filter[0] * tmp[index - 16] + 
                               filter[3] * tmp[index + 8] - filter[4] * tmp[index + 16] + filter[5] * tmp[index + 24] + 64) >> 7];
        }
        for (x = 0; x < 8; x++) {
            dst[x] = temp_vals[x];
        }
        dst += dststride;
        tmp += 8;
    }
}
