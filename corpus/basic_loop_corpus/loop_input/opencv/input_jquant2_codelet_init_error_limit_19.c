#include <stdlib.h>
#include <stdint.h>

int *table;
int in;
int out;

static int *table_storage;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data (sufficient for ~0.01 sec runtime)
    table_storage = aligned_alloc(64, data_size * sizeof(int));
    if (!table_storage) exit(1);

    // Initialize table to point to the middle of the allocated buffer
    // This allows negative indexing: table[-in] when in > 0 and within bounds
    table = &table_storage[data_size / 2];

    in = 0;
    out = 42; // arbitrary non-zero value
}