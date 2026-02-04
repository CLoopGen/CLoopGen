#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern int h;
extern int depth;
extern uint16_t *dsty;
extern int16_t *srcy;
extern ptrdiff_t stridey;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < h; j += 2) {
    for (i = 0; i < w; i++) {
        int64_t scaled_val, norm_factor = (int64_t)((1 << depth) - 1);
        int64_t square_factor = norm_factor * norm_factor;
        int active_src = srcy[i];

        if (active_src <= 0)
            dsty[i] = 0;
        else if (active_src > norm_factor)
            dsty[i] = 65535;
        else {
            scaled_val = (int64_t)active_src * active_src * 65535;
            dsty[i] = (uint16_t)(scaled_val / square_factor);
        }

        if (j + 1 < h) {
            int active_src_next = ((int16_t*)(((char*)srcy) + stridey))[i];
            uint16_t *dst_next = &((uint16_t*)(((char*)dsty) + stridey))[i];

            if (active_src_next <= 0)
                *dst_next = 0;
            else if (active_src_next > norm_factor)
                *dst_next = 65535;
            else {
                scaled_val = (int64_t)active_src_next * active_src_next * 65535;
                *dst_next = (uint16_t)(scaled_val / square_factor);
            }
        }
    }
    dsty += stridey * (j + 1 < h ? 2 : 1);
    srcy += stridey * (j + 1 < h ? 2 : 1);
}
}
