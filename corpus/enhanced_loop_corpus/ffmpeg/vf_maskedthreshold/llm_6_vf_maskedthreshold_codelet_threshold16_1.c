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
    uint16_t temp;
    for (int x = 0; x < w; x++) {
        temp = (src[x] > ref[x]) ? (src[x] - ref[x]) : (ref[x] - src[x]);
        dst[x] = (temp <= threshold) ? src[x] : ref[x];
    }
}
