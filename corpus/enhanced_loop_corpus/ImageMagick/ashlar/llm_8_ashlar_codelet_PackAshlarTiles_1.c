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
    for (i = 0; i < (ssize_t)number_tiles; i += 2) {
        if (i < (ssize_t)number_tiles) {
            tiles[i].order = i;
        }
        if (i + 1 < (ssize_t)number_tiles) {
            tiles[i + 1].order = i + 1;
        }
    }
}
