#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int64_t *fmts;
int count;

static int64_t *fmts_storage;

void init_vars() {
    size_t data_size = 1 << 20; // Approximately 8MB of data (1M int64_t elements)
    fmts_storage = malloc((data_size + 1) * sizeof(int64_t));
    if (!fmts_storage) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; i++) {
        fmts_storage[i] = rand();
    }
    fmts_storage[data_size] = -1; // Terminate condition

    fmts = fmts_storage;
    count = 0;
}