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
    for (y = 0; y < h + 4 - 1; y++) {
        int sum0, sum1;
        // Introduce local accumulation to create WAW and WAR dependencies within the iteration
        for (x = 0; x < 4; x++) {
            sum0 = filter[2] * local_src[x + 0] - filter[1] * local_src[x - 1] + filter[0] * local_src[x - 2]
                 + filter[3] * local_src[x + 1] - filter[4] * local_src[x + 2] + filter[5] * local_src[x + 3];
            sum1 = filter[2] * local_src[x + 4] - filter[1] * local_src[x + 3] + filter[0] * local_src[x + 2]
                 + filter[3] * local_src[x + 5] - filter[4] * local_src[x + 6] + filter[5] * local_src[x + 7];
            local_tmp[x]     = cm[(sum0 + 64) >> 7];
            local_tmp[x + 4] = cm[(sum1 + 64) >> 7];
        }
        local_tmp += 8;
        local_src += srcstride;
    }
}
