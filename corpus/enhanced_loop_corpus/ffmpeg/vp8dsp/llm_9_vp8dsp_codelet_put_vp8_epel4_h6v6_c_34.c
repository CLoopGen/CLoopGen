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
for (y = 0; y < h + 6 - 1; y += 2) {
    for (x = 0; x < 4; x++) {
        int sum1 = filter[2] * src[x + 0] - filter[1] * src[x - 1] + filter[0] * src[x - 2];
        int sum2 = filter[3] * src[x + 1] - filter[4] * src[x + 2] + filter[5] * src[x + 3];
        tmp[x] = cm[(sum1 + sum2 + 64) >> 7];
        if (y + 1 < h + 6 - 1) {
            int offset = srcstride;
            int val = (filter[2] * src[x + offset] 
                     - filter[1] * src[x + offset - 1] 
                     + filter[0] * src[x + offset - 2] 
                     + filter[3] * src[x + offset + 1] 
                     - filter[4] * src[x + offset + 2] 
                     + filter[5] * src[x + offset + 3] 
                     + 64) >> 7;
            tmp[4 + x] = cm[val];
        }
    }
    tmp += (y + 1 < h + 6 - 1) ? 8 : 4;
    src += (y + 1 < h + 6 - 1) ? 2 * srcstride : srcstride;
}
}
