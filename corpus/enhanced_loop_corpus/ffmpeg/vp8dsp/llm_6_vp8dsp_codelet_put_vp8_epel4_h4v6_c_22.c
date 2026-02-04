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
        int sum = 0;
        for (x = 0; x < 4; x++) {
            int val = filter[2] * local_src[x + 0] - 
                      filter[1] * local_src[x - 1] + 
                      filter[3] * local_src[x + 1] - 
                      filter[4] * local_src[x + 2];
            sum += val; // Introduce intra-loop dependency: cumulative sum
            local_tmp[x] = cm[(sum + 64) >> 7]; // WAW and RAW dependency on 'sum' and previous writes to local_tmp
        }
        local_tmp += 4;
        local_src += srcstride;
    }
}
