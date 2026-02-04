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
    const size_t data_size = 1 << 20; // 1MB of IDWTELEM data (~65536 elements)

    low_storage = (IDWTELEM*)calloc(data_size, sizeof(IDWTELEM));
    high_storage = (IDWTELEM*)calloc(data_size / 2, sizeof(IDWTELEM));

    low = low_storage;
    high = high_storage;

    i_storage = data_size - 2; // Ensure (*i) starts at valid even index

    // Initialize arrays to avoid undefined behavior
    for (size_t idx = 0; idx < data_size; ++idx) {
        low_storage[idx] = (IDWTELEM)(idx & 0xFFFF);
    }
    for (size_t idx = 0; idx < data_size / 2; ++idx) {
        high_storage[idx] = (IDWTELEM)((idx + 0x8000) & 0xFFFF);
    }
}