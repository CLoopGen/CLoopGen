#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t dwtcoef;

int height;
int x;
int y;
dwtcoef *synthl;
ptrdiff_t synth_width;

static dwtcoef *buffer;

void init_vars() {
    const size_t total_size = 1 << 20; // ~1MB of data
    buffer = (dwtcoef*)calloc(total_size, sizeof(dwtcoef));
    if (!buffer) exit(1);

    height = 256;
    synth_width = 256;

    synthl = buffer + 2 * synth_width; // offset to allow x - 2*synth_width access
}

__attribute__((destructor))
static void cleanup() {
    free(buffer);
}