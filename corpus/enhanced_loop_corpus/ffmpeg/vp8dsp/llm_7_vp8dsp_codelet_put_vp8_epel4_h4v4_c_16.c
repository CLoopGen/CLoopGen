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
    uint8_t *local_tmp = tmp;
    const uint8_t *local_src = src;
    ptrdiff_t stride = srcstride;
    const uint8_t *local_filter = filter;
    const uint8_t *local_cm = cm;
    int local_h = h;

    for (y = 0; y < local_h + 4 - 1; y++) {
        int offset = 0;
        for (x = 0; x < 4; x++) {
            int val = local_filter[2] * local_src[x + offset] -
                     local_filter[1] * local_src[x - 1 + offset] +
                     local_filter[3] * local_src[x + 1 + offset] -
                     local_filter[4] * local_src[x + 2 + offset] + 64;
            local_tmp[x] = local_cm[val >> 7];

            offset += (y & 1); // Introduce conditional offset based on loop index (adds WAR-like dependency pattern)
        }
        local_tmp += 4;
        local_src += stride;
    }
}
