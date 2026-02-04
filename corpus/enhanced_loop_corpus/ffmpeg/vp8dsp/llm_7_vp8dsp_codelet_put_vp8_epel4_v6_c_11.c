#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dststride;
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern int h;
extern  uint8_t *filter;
extern  uint8_t *cm;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int y, x;
    uint8_t local_filter[6];
    uint8_t local_cm[256];
    ptrdiff_t local_dststride = dststride;
    ptrdiff_t local_srcstride = srcstride;
    int local_h = h;

    for (int i = 0; i < 6; i++) {
        local_filter[i] = filter[i];
    }
    for (int i = 0; i < 256; i++) {
        local_cm[i] = cm[i];
    }

    for (y = 0; y < local_h; y++) {
        uint8_t *local_dst = &dst[y * local_dststride];
        uint8_t *local_src = &src[y * local_srcstride];
        for (x = 0; x < 4; x++) {
            int index = (local_filter[2] * local_src[x + 0 * local_srcstride] 
                       - local_filter[1] * local_src[x - 1 * local_srcstride] 
                       + local_filter[0] * local_src[x - 2 * local_srcstride] 
                       + local_filter[3] * local_src[x + 1 * local_srcstride] 
                       - local_filter[4] * local_src[x + 2 * local_srcstride] 
                       + local_filter[5] * local_src[x + 3 * local_srcstride] + 64) >> 7;
            local_dst[x] = local_cm[index];
        }
    }
}
