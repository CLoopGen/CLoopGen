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
    for (x = 0; x < w; x++) {
        int adjusted_val = src[x];
        int neighbor_val = src[x + 1];
        int interpolated = (adjusted_val + ((mx * (neighbor_val - adjusted_val) + 8) >> 4));
        if (x % 2 == 0) {
            tmp_ptr[x] = interpolated;
        } else {
            tmp_ptr[x] = adjusted_val;
        }
    }
}
