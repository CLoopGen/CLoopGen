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
        int diff = src[x] - ref[x];
        if (diff < 0) diff = -diff;
        if (diff <= threshold)
            dst[x] = src[x];
        else
            dst[x] = ref[x];
    }
}
