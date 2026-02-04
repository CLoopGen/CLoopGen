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
    for (y = 0; y < h + 6 - 1; y++) {
        for (x = 0; x < 4; x++) {
            int val = filter[2] * local_src[x] 
                    - filter[1] * local_src[x - 1] 
                    + filter[0] * local_src[x - 2] 
                    + filter[3] * local_src[x + 1] 
                    - filter[4] * local_src[x + 2] 
                    + filter[5] * local_src[x + 3];
            local_tmp[x] = cm[(val + 64) >> 7];
            if (x > 0) {
                local_tmp[x] ^= local_tmp[x - 1]; // Introduce WAW and RAW dependency: current output depends on previous output
            }
        }
        local_tmp += 4;
        local_src += srcstride;
    }
}
