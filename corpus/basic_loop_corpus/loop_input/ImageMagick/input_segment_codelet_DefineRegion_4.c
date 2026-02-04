#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct _ExtentPacket {
    double center;
    ssize_t index;
    ssize_t left;
    ssize_t right;
} ExtentPacket;

short *extrema;
ExtentPacket *extents;

void init_vars() {
    size_t extrema_size = 1 << 20;
    extrema = (short*)calloc(extrema_size, sizeof(short));
    if (!extrema) exit(1);

    extents = (ExtentPacket*)malloc(sizeof(ExtentPacket));
    if (!extents) exit(1);

    extents->index = 0;
    extents->center = 0.0;
    extents->left = 0;
    extents->right = 0;

    for (ssize_t i = 0; i < 256; i++) {
        extrema[i] = (short)(i == 255 ? 1 : 0);
    }
}