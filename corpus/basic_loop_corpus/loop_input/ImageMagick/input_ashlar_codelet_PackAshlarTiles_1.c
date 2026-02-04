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

size_t number_tiles;
CanvasInfo *tiles;
ssize_t i;

void init_vars() {
    number_tiles = 10000000; // 10 million elements, adjust for ~0.01 sec runtime

    tiles = (CanvasInfo*)calloc(number_tiles, sizeof(CanvasInfo));
    if (!tiles) {
        exit(1);
    }

    for (size_t idx = 0; idx < number_tiles; idx++) {
        tiles[idx].id = idx;
        tiles[idx].width = 800;
        tiles[idx].height = 600;
        tiles[idx].x = 100;
        tiles[idx].y = 100;
        tiles[idx].order = -1; // initial value before loop
    }
}