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
        int diff = src[x] - ref[x];
        if (diff < 0) diff = -diff;
        if (diff <= threshold)
            dst[x] = src[x];
        else
            dst[x] = ref[x];
    }
}
