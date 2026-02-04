#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int i;
int16_t *block;

void init_vars() {
    const size_t data_size = 1 << 20;
    block = (int16_t*)aligned_alloc(32, data_size * sizeof(int16_t));
    if (!block) exit(1);
    for (size_t idx = 0; idx < data_size; ++idx) {
        block[idx] = (int16_t)(idx % 512 - 256);
    }
}