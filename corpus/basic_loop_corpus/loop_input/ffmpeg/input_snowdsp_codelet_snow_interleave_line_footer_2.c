#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef short IDWTELEM;

static int i_storage;
static IDWTELEM *low_storage;
static IDWTELEM *high_storage;

int *i = &i_storage;
IDWTELEM *low = NULL;
IDWTELEM *high = NULL;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data (adjustable)

    low_storage = (IDWTELEM *)aligned_alloc(32, data_size * sizeof(IDWTELEM));
    high_storage = (IDWTELEM *)aligned_alloc(32, data_size * sizeof(IDWTELEM));

    if (!low_storage || !high_storage) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        low_storage[idx] = (IDWTELEM)(idx & 0xFFFF);
        high_storage[idx] = (IDWTELEM)((idx + 1) & 0xFFFF);
    }

    low = low_storage;
    high = high_storage;
    i_storage = data_size - 2;
}