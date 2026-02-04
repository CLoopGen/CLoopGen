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
    size_t extrema_size = 1024 * 1024; // ~2MB of short data (1MB elements)
    extrema = (short*)calloc(extrema_size, sizeof(short));
    if (!extrema) exit(1);

    extents = (ExtentPacket*)calloc(1, sizeof(ExtentPacket));
    if (!extents) exit(1);

    extents->index = 0;
    extents->center = 0.0;
    extents->left = 0;
    extents->right = 0;

    for (size_t i = 0; i < extrema_size; i++) {
        extrema[i] = (short)(rand() % 3 - 1); // values: -1, 0, or 1
    }

    // Ensure that the loop runs for a while but eventually breaks
    // Set first 256 entries to non-negative, so break occurs at index 256 only if extrema[256] < 0
    for (int i = 0; i < 256; i++) {
        extrema[i] = (short)(rand() % 2); // 0 or 1
    }
    // Make sure extrema[256] is negative to trigger break at index == 256
    if (extrema[256] >= 0)
        extrema[256] = -1;
}