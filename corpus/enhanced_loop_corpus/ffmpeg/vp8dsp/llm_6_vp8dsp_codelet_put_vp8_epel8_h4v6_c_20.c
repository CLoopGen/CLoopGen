#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern int h;
extern  uint8_t *filter;
extern  uint8_t *cm;
extern int x;
extern int y;
extern uint8_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *tmp_base = tmp;
    for (y = 0; y < h + 6 - 1; y++) {
        uint8_t local_tmp[8];
        for (x = 0; x < 8; x++) {
            int index = (filter[2] * src[x + 0 * 1] - filter[1] * src[x - 1 * 1] +
                        filter[3] * src[x + 1 * 1] - filter[4] * src[x + 2 * 1] + 64) >> 7;
            local_tmp[x] = cm[index];
        }
        for (x = 0; x < 8; x++) {
            tmp_base[y * 8 + x] = local_tmp[x];
        }
    }
    tmp = tmp_base + (h + 6 - 1) * 8;
    src += (h + 6 - 1) * srcstride;
}
