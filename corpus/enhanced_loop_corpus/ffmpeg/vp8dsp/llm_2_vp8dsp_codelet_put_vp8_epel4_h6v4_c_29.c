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
        uint8_t temp_vals[4];
        for (x = 0; x < 4; x++) {
            temp_vals[x] = tmp[x];
        }
        for (x = 0; x < 4; x++) {
            int index = (filter[2] * temp_vals[x] - 
                        filter[1] * ((x > 0) ? temp_vals[x-1] : tmp[-1 * 4]) + 
                        filter[3] * ((x < 3) ? temp_vals[x+1] : tmp[1 * 4]) - 
                        filter[4] * ((x < 2) ? temp_vals[x+2] : tmp[2 * 4]) + 64) >> 7;
            dst[x] = cm[index];
        }
        dst += dststride;
        tmp += 4;
    }
}
