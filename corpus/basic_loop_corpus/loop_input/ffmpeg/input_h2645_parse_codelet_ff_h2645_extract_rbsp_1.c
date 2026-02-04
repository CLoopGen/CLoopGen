#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint8_t *src;
int length;
int i;

static uint8_t *internal_src;
static const size_t DATA_SIZE = 128 * 1024 * 1024; // 128 MB

void init_vars() {
    internal_src = (uint8_t*)aligned_alloc(32, DATA_SIZE);
    if (!internal_src) {
        exit(1);
    }
    src = internal_src;
    length = DATA_SIZE;
    i = 0;

    memset(internal_src, 0, DATA_SIZE);

    for (size_t idx = 0; idx < DATA_SIZE; idx += 1000) {
        internal_src[idx] = 1;
    }

    size_t trigger_index = DATA_SIZE / 2;
    internal_src[trigger_index] = 0;
    internal_src[trigger_index - 1] = 0;
    internal_src[trigger_index + 1] = 0;
    internal_src[trigger_index + 2] = 1;
}