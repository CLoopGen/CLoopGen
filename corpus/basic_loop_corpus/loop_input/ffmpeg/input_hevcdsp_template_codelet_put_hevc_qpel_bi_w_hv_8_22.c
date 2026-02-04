#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int height = 64;
int width = 64;
int x;
int y;

int8_t filter_data[8] = {1, -2, 3, -4, 5, -6, 7, -8};
int8_t *filter = filter_data;

uint8_t *src;
ptrdiff_t srcstride = 64;

int16_t *tmp;

void init_vars() {
    const size_t total_size = 1024 * 1024 * 4; // ~4MB of data to ensure sufficient runtime
    const int padded_width = 64;
    const int padded_height = (total_size / padded_width) / sizeof(uint8_t);
    height = padded_height - 7; // Adjust so that y < height + 7 stays within bounds

    if (height <= 0) height = 64;

    width = padded_width;

    src = aligned_alloc(64, (height + 7) * srcstride);
    tmp = aligned_alloc(64, (height + 7) * 64 * sizeof(int16_t));

    for (int i = 0; i < (height + 7) * srcstride; i++) {
        src[i] = rand() % 256;
    }

    for (int i = 0; i < (height + 7) * 64; i++) {
        tmp[i] = 0;
    }
}