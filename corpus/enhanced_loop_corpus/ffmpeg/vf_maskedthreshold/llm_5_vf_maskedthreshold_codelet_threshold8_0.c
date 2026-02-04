#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern  uint8_t *ref;
extern uint8_t *dst;
extern int threshold;
extern int w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int x = 0; x < w; x++) {
        uint8_t s = src[x], r = ref[x];
        int abs_diff = (s >= r) ? (s - r) : (r - s);
        dst[x] = (abs_diff <= threshold) ? s : r;
    }
}
