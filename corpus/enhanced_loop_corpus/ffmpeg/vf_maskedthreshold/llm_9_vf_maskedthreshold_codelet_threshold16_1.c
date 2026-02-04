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
        int sum = src[x] + ref[x];
        int diff = src[x] - ref[x];
        int squared_diff = diff * diff;
        int normalized = squared_diff >> 4;
        dst[x] = normalized <= (threshold * threshold) ? (sum >> 1) : ref[x];
    }
}
