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
    uint8_t local_filter[5];
    for (int i = 0; i < 5; i++) {
        local_filter[i] = filter[i];
    }
    for (y = 0; y < h; y++) {
        uint8_t temp_vals[4];
        for (x = 0; x < 4; x++) {
            int val = local_filter[2] * tmp[x + 0 * 4] - 
                      local_filter[1] * tmp[x - 1 * 4] + 
                      local_filter[3] * tmp[x + 1 * 4] - 
                      local_filter[4] * tmp[x + 2 * 4] + 64;
            temp_vals[x] = cm[val >> 7];
        }
        for (x = 0; x < 4; x++) {
            dst[x] = temp_vals[x];
        }
        dst += dststride;
        tmp += 4;
    }
}
