#include <stdint.h>
#include <stdlib.h>

uint8_t *top;
int i;
uint8_t v[7];

static uint8_t *top_data;

void init_vars() {
    size_t data_size = 1 << 20; // ~1MB of data
    top_data = aligned_alloc(32, data_size);
    if (!top_data) exit(1);

    for (size_t idx = 0; idx < data_size; ++idx) {
        top_data[idx] = rand() & 0xFF;
    }

    top = top_data;

    for (int j = 0; j < 7; ++j) {
        v[j] = 0;
    }
}