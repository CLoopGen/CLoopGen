#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern int mx;
extern uint8_t *tmp_ptr;
extern  uint8_t *src;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    for (x = 0; x < w; x += step) {
        if (x + 1 < w) {
            tmp_ptr[x] = (src[x] + ((mx * (src[x + 1] - src[x]) + 8) >> 4));
        }
        if (x + 2 < w) {
            tmp_ptr[x + 1] = (src[x + 1] + ((mx * (src[x + 2] - src[x + 1]) + 8) >> 4));
        }
    }
}
