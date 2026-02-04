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
for (y = 0; y < (h + 2) / 2; y++) {
    for (x = 0; x < 4; x++) {
        int offset0 = x + 0;
        int offset1 = x + 1;
        int base_val = filter[2] * src[offset0] + filter[3] * src[offset1] + 64;
        int diff_val = -filter[1] * src[x - 1] - filter[4] * src[x + 2];
        tmp[x] = cm[(base_val + diff_val) >> 7];
    }
    tmp += 4;
    src += 2 * srcstride;
}
}
