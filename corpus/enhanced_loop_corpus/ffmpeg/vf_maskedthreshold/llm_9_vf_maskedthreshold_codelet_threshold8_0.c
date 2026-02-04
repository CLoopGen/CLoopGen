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
    int x;
    int scaled_threshold = threshold * 2;
    for (x = 0; x < w; x++) {
        int sum = src[x] + ref[x];
        int diff = src[x] - ref[x];
        int squared_diff = diff * diff;
        int normalized = (squared_diff / (sum + 1)) <= scaled_threshold;
        dst[x] = normalized ? src[x] : ref[x];
    }
}
