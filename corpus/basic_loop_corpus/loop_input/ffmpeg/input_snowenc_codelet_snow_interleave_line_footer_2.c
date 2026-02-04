#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef short IDWTELEM;

IDWTELEM *low;
IDWTELEM *high;
int *i;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data (adjustable)
    low = (IDWTELEM*)calloc(data_size, sizeof(IDWTELEM));
    high = (IDWTELEM*)calloc(data_size / 2, sizeof(IDWTELEM));

    if (!low || !high) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size / 2; ++idx) {
        high[idx] = (IDWTELEM)(idx & 0xFFFF);
    }
    for (size_t idx = 0; idx < data_size; ++idx) {
        low[idx] = (IDWTELEM)((idx + 1) & 0xFFFF);
    }

    i = (int*)malloc(sizeof(int));
    if (!i) {
        exit(1);
    }
    *i = (int)(data_size - 2); // Ensure (*i) >= 0 and even, so loop runs safely
}