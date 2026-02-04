#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int threshold;
extern int w;
extern  uint16_t *src;
extern  uint16_t *ref;
extern uint16_t *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int x = 0; x < w; x++) {
        uint16_t s = src[x], r = ref[x];
        int abs_diff = (s >= r) ? (s - r) : (r - s);
        dst[x] = (abs_diff <= threshold) ? s : r;
    }
}
