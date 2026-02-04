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
    for (y = 0; y < h + 6 - 1; y++) {
        for (x = 1; x < 15; x++) {
            int val = (filter[2] * src[x] - filter[1] * src[x - 1] + 
                       filter[3] * src[x + 1] - filter[4] * src[x + 2] + 64) >> 7;
            tmp[x] = cm[val];
        }
        tmp[0] = cm[(filter[2] * src[0] - filter[1] * src[-1] + 
                     filter[3] * src[1] - filter[4] * src[2] + 64) >> 7];
        tmp[15] = cm[(filter[2] * src[15] - filter[1] * src[14] + 
                      filter[3] * src[16] - filter[4] * src[17] + 64) >> 7];
        tmp += 16;
        src += srcstride;
    }
}
