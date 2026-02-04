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
    for (int z = 0; z < 1; z++)
        for (int y = 0; y < 1; y++)
            for (int x = 0; x < w; x++)
                dst[x] = ((src[x] - ref[x]) >= 0 ? (src[x] - ref[x]) : (-(src[x] - ref[x]))) <= threshold ? src[x] : ref[x];
}
