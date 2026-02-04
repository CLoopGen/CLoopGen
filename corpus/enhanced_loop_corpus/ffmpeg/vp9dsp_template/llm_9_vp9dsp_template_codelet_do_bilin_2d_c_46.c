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
    for (x = 0; x < w && x < 64; x++) {
        int diff1 = src[x + 1] - src[x];
        int diff2 = (x + 2 < w) ? src[x + 2] - src[x + 1] : diff1;
        int weighted_avg = (mx * (diff1 + diff2 + (src[x] >> 1)) + 16) >> 5;
        tmp_ptr[x] = src[x] + weighted_avg;
    }
}
