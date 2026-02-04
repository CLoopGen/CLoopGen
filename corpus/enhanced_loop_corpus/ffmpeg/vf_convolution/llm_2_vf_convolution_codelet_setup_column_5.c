#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int radius;
extern  uint8_t *c[];
extern  uint8_t *src;
extern int stride;
extern int x;
extern int y;
extern int h;
extern int bpc;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < radius * 2 + 1; i++) {
        int index = x + i - radius;
        index = (index < 0) ? -index : index;
        index = (index >= h) ? 2 * h - 1 - index : index;
        // Use consecutive memory layout assumption: transpose access pattern
        // Assume c is now accessed in a strided manner with fixed offset per iteration
        c[i] = src + index * stride + y * bpc;
    }
}
