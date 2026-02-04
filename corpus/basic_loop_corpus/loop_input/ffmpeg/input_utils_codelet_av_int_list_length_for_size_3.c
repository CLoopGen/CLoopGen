#include <stdint.h>
#include <stdlib.h>

unsigned int i;
uint64_t t;
uint64_t *l;

static uint64_t *l_storage;

void init_vars() {
    const size_t data_size = 32 * 1024 * 1024; // ~256 MB of data (32M elements × 8 bytes)
    l_storage = aligned_alloc(64, data_size * sizeof(uint64_t));
    if (!l_storage) exit(1);

    for (size_t idx = 0; idx < data_size - 1; ++idx) {
        l_storage[idx] = 0;
    }
    l_storage[data_size - 1] = 0xDEADBEEFDEADBEEFull;

    l = l_storage;
    t = 0xDEADBEEFDEADBEEFull;

    i = 0;
}