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

typedef enum {
    MagickFalse = 0,
    MagickTrue = 1
} MagickBooleanType;

size_t number_tiles = 1000000; // ~1M elements for ~0.01 sec runtime
CanvasInfo *tiles = NULL;
MagickBooleanType status = MagickTrue;
ssize_t i = 0;

void init_vars() {
    tiles = (CanvasInfo*)calloc(number_tiles, sizeof(CanvasInfo));
    if (!tiles) {
        exit(1);
    }

    for (size_t idx = 0; idx < number_tiles; idx++) {
        tiles[idx].id = idx;
        tiles[idx].width = 800;
        tiles[idx].height = 600;
        tiles[idx].x = (idx % 7 == 0) ? 9223372036854775807L : (ssize_t)(idx * 10);
        tiles[idx].y = (idx % 11 == 0) ? 9223372036854775807L : (ssize_t)(idx * 15);
        tiles[idx].order = -1; // uninitialized state
    }

    status = MagickTrue;
    i = 0;
}