#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *hist;
int32_t *vector;
int i;

static int32_t *hist_buffer;
static int32_t *vector_buffer;

void init_vars() {
    size_t data_size = 1024 * 1024; // ~4MB of data (1MB elements * 4 bytes per int32_t)
    hist_buffer = calloc(data_size, sizeof(int32_t));
    vector_buffer = calloc(data_size, sizeof(int32_t));

    if (!hist_buffer || !vector_buffer) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; idx++) {
        hist_buffer[idx] = (int32_t)(idx % 1000);
    }

    hist = hist_buffer;
    vector = vector_buffer;
}

__attribute__((constructor))
void constructor() {
    init_vars();
}