#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern  int8_t *filter;
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < height + 15; y += 2) {
    for (x = 0; x < width; x++) {
        int32_t sum = 0;
        for (int k = 0; k < 4; k++) {
            sum += filter[k] * src[x + (k - 3)];
        }
        for (int k = 4; k < 8; k++) {
            sum += filter[k] * src[x + (k - 3)];
        }
        tmp[x] = sum >> 8;
    }
    src += srcstride;
    tmp += 64;

    if (y + 1 < height + 15) {
        for (x = 0; x < width; x++) {
            tmp[x] = (filter[0] * src[x - 3] + filter[1] * src[x - 2] + filter[2] * src[x - 1] + 
                      filter[3] * src[x] + filter[4] * src[x + 1] + filter[5] * src[x + 2] + 
                      filter[6] * src[x + 3] + filter[7] * src[x + 4]) >> 8;
        }
        src += srcstride;
        tmp += 64;
    }
}
}
