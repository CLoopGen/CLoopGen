#include <stdint.h>
#include <stdlib.h>

uint8_t i;
int16_t *filter_ptr1;

static int16_t *filter_array;

void init_vars() {
    const size_t total_size = 1 << 20;
    filter_array = (int16_t *)aligned_alloc(16, total_size * sizeof(int16_t));
    if (!filter_array) abort();

    for (size_t idx = 0; idx < total_size; idx++) {
        filter_array[idx] = (int16_t)(idx & 0x7FFF);
    }

    filter_ptr1 = filter_array;
}