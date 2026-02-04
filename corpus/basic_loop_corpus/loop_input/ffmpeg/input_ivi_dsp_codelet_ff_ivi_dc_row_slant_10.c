#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *out;
ptrdiff_t pitch;
int blk_size;
int x;
int y;

static int16_t *data_buffer;
static size_t buffer_size;

void init_vars() {
    blk_size = 4096;  
    buffer_size = (size_t)blk_size * blk_size * sizeof(int16_t);
    data_buffer = aligned_alloc(32, buffer_size);
    if (!data_buffer) {
        exit(1);
    }
    out = data_buffer;
    pitch = blk_size;
}

__attribute__((destructor))
static void cleanup() {
    free(data_buffer);
}