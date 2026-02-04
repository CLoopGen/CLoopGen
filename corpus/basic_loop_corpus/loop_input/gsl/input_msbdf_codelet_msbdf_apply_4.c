#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t * ordprev;
size_t * ordprevbackup;
size_t i;

void init_vars() {
    const size_t data_size = 16777216; // 16MB of data (2^24 bytes / sizeof(size_t) * 2 arrays)

    ordprev = (size_t*)aligned_alloc(64, data_size * sizeof(size_t));
    ordprevbackup = (size_t*)aligned_alloc(64, data_size * sizeof(size_t));

    for (size_t idx = 0; idx < data_size; idx++) {
        ordprev[idx] = idx * 31 + 1;
        ordprevbackup[idx] = 0;
    }
}

__attribute__((constructor))
static void constructor() {
    init_vars();
}