#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dststride;
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern int h;
extern  uint8_t *filter;
extern  uint8_t *cm;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h; y++) {
    uint8_t *d = dst + y * dststride;
    const uint8_t *s = src + y * srcstride;
    const ptrdiff_t s_off[4] = {0, -1, 1, 2};
    for (x = 0; x < 16; x++) {
        int sum = filter[2] * s[x + s_off[0]] 
                - filter[1] * s[x + s_off[1]] 
                + filter[3] * s[x + s_off[2]] 
                - filter[4] * s[x + s_off[3]] 
                + 64;
        d[x] = cm[sum >> 7];
    }
}
}
