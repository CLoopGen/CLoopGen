#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
ptrdiff_t w;
int acc;
int i;

void init_vars() {
    size_t data_size = 128 << 20; // 128 MB

    src = (uint8_t *)aligned_alloc(32, data_size);
    dst = (uint8_t *)aligned_alloc(32, data_size);

    for (size_t j = 0; j < data_size; j++) {
        src[j] = (uint8_t)(j & 0xFF);
    }

    w = data_size - (data_size % 2); // Ensure w is even so we don't overstep in loop
    acc = 0;
}