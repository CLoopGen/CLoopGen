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
        int skip_computation = (y == 0 || y == h + 6 - 2);
        if (!skip_computation) {
            for (x = 0; x < 16; x++) {
                int index = x + 1; // Shift access pattern
                int val = (filter[2] * src[index] - filter[1] * src[index - 1] + 
                          filter[0] * src[index - 2] + filter[3] * src[index + 1] - 
                          filter[4] * src[index + 2] + filter[5] * src[index + 3] + 64) >> 7;
                tmp[x] = cm[val];
            }
        } else {
            for (x = 0; x < 16; x++) {
                tmp[x] = 0; // Simplified path: zero output on first and last iteration
            }
        }
        tmp += 16;
        src += srcstride;
    }
}
