#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *msrc;
extern  uint8_t *asrc;
extern uint8_t *dst;
extern ptrdiff_t mlinesize;
extern ptrdiff_t alinesize;
extern ptrdiff_t dlinesize;
extern int w;
extern int h;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h; y += 2) {
    for (x = 0; x < w; x++) {
        int adjusted_val;
        uint8_t curr_m = msrc[x], curr_a = asrc[x];

        if (curr_a == 0) {
            dst[x] = 128;
        } else if (curr_a >= 255) {
            dst[x] = curr_m;
        } else {
            adjusted_val = (curr_m - 128) * (255 / (double)curr_a) + 128;
            dst[x] = (adjusted_val < 0) ? 0 : (adjusted_val > 255) ? 255 : adjusted_val;
        }

        if (y + 1 < h) {
            uint8_t next_m = (msrc + mlinesize)[x];
            uint8_t next_a = (asrc + alinesize)[x];
            uint8_t* next_dst = dst + dlinesize;

            if (next_a == 0) {
                next_dst[x] = 128;
            } else if (next_a >= 255) {
                next_dst[x] = next_m;
            } else {
                adjusted_val = (next_m - 128) * (255 / (double)next_a) + 128;
                next_dst[x] = (adjusted_val < 0) ? 0 : (adjusted_val > 255) ? 255 : adjusted_val;
            }
        }
    }
    dst += 2 * dlinesize;
    msrc += 2 * mlinesize;
    asrc += 2 * alinesize;
}
}
