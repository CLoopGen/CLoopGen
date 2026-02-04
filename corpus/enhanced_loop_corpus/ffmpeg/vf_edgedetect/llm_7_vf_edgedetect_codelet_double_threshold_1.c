#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int low;
extern int high;
extern int w;
extern int h;
extern uint8_t *dst;
extern int dst_linesize;
extern  uint8_t *src;
extern int src_linesize;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *local_dst = dst;
    uint8_t *local_src = src;
    int local_w = w;
    int local_h = h;
    int local_low = low;
    int local_high = high;
    int local_sl = src_linesize;
    int local_dl = dst_linesize;

    for (j = 0; j < local_h; j++) {
        for (i = 0; i < local_w; i++) {
            if (local_src[i] > local_high) {
                local_dst[i] = local_src[i];
                continue;
            }
            if ((!i || i == local_w - 1 || j == 0 || j == local_h - 1) && 
                local_src[i] > local_low) {
                int found = 0;
                int offsets[] = {-local_sl - 1, -local_sl, -local_sl + 1,
                                -1,               1,
                                 local_sl - 1,    local_sl,     local_sl + 1};
                for (int n = 0; n < 8; n++) {
                    if (local_src[i + offsets[n]] > local_high) {
                        found = 1;
                        break;
                    }
                }
                local_dst[i] = found ? local_src[i] : 0;
            } else {
                local_dst[i] = 0;
            }
        }
        local_dst += local_dl;
        local_src += local_sl;
    }
    dst = local_dst;
    src = local_src;
}
