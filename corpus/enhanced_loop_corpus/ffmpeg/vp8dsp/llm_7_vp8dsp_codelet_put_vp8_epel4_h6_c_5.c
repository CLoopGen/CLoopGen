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
        int offset = y * local_dststride;
        for (x = 0; x < 4; x++) {
            int index = x + y * local_srcstride;
            int val = local_filter[2] * src[index + 0]
                    - local_filter[1] * src[index - 1]
                    + local_filter[0] * src[index - 2]
                    + local_filter[3] * src[index + 1]
                    - local_filter[4] * src[index + 2]
                    + local_filter[5] * src[index + 3];
            dst[offset + x] = local_cm[(val + 64) >> 7];
        }
    }
}
