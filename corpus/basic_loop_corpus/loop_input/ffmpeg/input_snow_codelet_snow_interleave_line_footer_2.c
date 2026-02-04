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

    low_storage = (IDWTELEM *)calloc(data_size, sizeof(IDWTELEM));
    high_storage = (IDWTELEM *)calloc(data_size / 2, sizeof(IDWTELEM));

    if (!low_storage || !high_storage) {
        exit(1);
    }

    low = low_storage;
    high = high_storage;

    i_storage = data_size - 2;
}