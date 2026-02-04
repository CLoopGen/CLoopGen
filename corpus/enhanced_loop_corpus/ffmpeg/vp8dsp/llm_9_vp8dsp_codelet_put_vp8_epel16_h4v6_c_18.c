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
for (y = 0; y < (h + 5) / 2; y++) {
    for (x = 0; x < 8; x++) {
        int offset = x * 2;
        int base_val = (filter[2] * src[offset] - filter[1] * src[offset - 1] + 
                        filter[3] * src[offset + 1] - filter[4] * src[offset + 2] + 64) >> 7;
        tmp[offset] = cm[base_val];
        if (offset + 1 < 16) {
            int next_val = (filter[2] * src[offset + 1] - filter[1] * src[offset] + 
                            filter[3] * src[offset + 2] - filter[4] * src[offset + 3] + 64) >> 7;
            tmp[offset + 1] = cm[next_val];
        }
    }
    tmp += 16;
    src += srcstride;
    // Process second row in unrolled fashion
    if (y * 2 + 1 < h + 5) {
        for (x = 0; x < 16; x++) {
            tmp[x] = cm[(filter[2] * src[x] - filter[1] * src[x - 1] + 
                         filter[3] * src[x + 1] - filter[4] * src[x + 2] + 64) >> 7];
        }
        tmp += 16;
        src += srcstride;
    }
}
}
