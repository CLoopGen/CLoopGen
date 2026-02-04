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
    // Variant 1: Consecutive memory access with manual stride simulation using pointer arithmetic
    uint8_t *d = dst;
    uint8_t *s = src;
    for (y = 0; y < h; y++) {
        uint8_t *row_s = s;
        for (x = 0; x < 4; x++) {
            int sum = filter[2] * row_s[x + 0] 
                    - filter[1] * row_s[x - 1] 
                    + filter[0] * row_s[x - 2] 
                    + filter[3] * row_s[x + 1] 
                    - filter[4] * row_s[x + 2] 
                    + filter[5] * row_s[x + 3] 
                    + 64;
            d[x] = cm[sum >> 7];
        }
        d += dststride;
        s += srcstride;
    }
}
