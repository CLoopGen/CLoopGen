#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t dwtcoef;

int x;
dwtcoef *synthl;
ptrdiff_t synth_width;

static dwtcoef *synthl_storage;
static ptrdiff_t total_size;

void init_vars() {
    // Aim for ~64MB of data to ensure loop runs long enough (~0.01 sec on modern CPU)
    total_size = (64 * 1024 * 1024) / sizeof(dwtcoef);  // ~64MB array
    synthl_storage = (dwtcoef*)calloc(total_size, sizeof(dwtcoef));
    if (!synthl_storage) {
        exit(1);
    }

    // Set synth_width to leave room for the largest offset used in the loop: x - 5*synth_width
    // We require at least 5*synth_width <= index range, so synth_width must be small enough
    // Let's set synth_width to about 1/6 of total size to allow safe access across all negative offsets
    synth_width = total_size / 6;
    if (synth_width < 100) {
        exit(1);  // Avoid unreasonably small width
    }

    // Base pointer is shifted forward so that during loop, x from 0 to synth_width-1
    // accesses within valid range, including negative offsets down to -5*synth_width
    // So we need at least 5*synth_width of prefix space before synthl[0]
    ptrdiff_t prefix = 5 * synth_width;
    if (prefix + synth_width >= total_size) {
        exit(1);
    }
    synthl = synthl_storage + prefix;

    // Initialize array with non-zero values to make computation meaningful
    for (ptrdiff_t i = 0; i < total_size; i++) {
        synthl_storage[i] = (dwtcoef)(i & 0xFF);
    }

    x = 0;
}