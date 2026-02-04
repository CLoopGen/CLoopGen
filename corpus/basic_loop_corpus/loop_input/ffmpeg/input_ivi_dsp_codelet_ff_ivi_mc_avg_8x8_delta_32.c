#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *buf;
ptrdiff_t pitch;
int16_t tmp[64];
int i;
int j;

static int16_t *buf_storage;
static ptrdiff_t pitch_value;

void init_vars() {
    const size_t total_size = 1 << 20; // 1MB of data
    const int block_count = total_size / (8 * sizeof(int16_t));
    const int height = block_count;

    buf_storage = (int16_t*)calloc(total_size, 1);
    if (!buf_storage) exit(1);

    pitch_value = 8;
    pitch = pitch_value;

    buf = buf_storage;
    for (i = 0; i < 64; ++i) {
        tmp[i] = (int16_t)(i - 32);
    }
    i = 0;
    j = 0;
}