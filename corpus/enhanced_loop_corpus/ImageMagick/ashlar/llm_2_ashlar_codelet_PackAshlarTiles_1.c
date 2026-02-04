#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _CanvasInfo {
    ssize_t id;
    size_t width;
    size_t height;
    ssize_t x;
    ssize_t y;
    ssize_t order;
} CanvasInfo;

extern  size_t number_tiles;
extern CanvasInfo *tiles;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern
    // Access every second element forward, then handle remainder
    ssize_t stride = 2;
    ssize_t limit = (ssize_t)number_tiles;

    for (i = 0; i < limit; i += stride) {
        tiles[i].order = i;
        if (i + 1 < limit) {
            tiles[i + 1].order = i + 1;
        }
    }
}
