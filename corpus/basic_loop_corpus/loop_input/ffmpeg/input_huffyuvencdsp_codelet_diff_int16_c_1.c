#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t *dst;
uint16_t *src1;
uint16_t *src2;
unsigned int mask;
int w;
long i;

static size_t data_size = 64 * (1 << 20); // 64 MB of data

void init_vars() {
    if (data_size % sizeof(uint16_t) != 0) {
        data_size = (data_size / sizeof(uint16_t)) * sizeof(uint16_t);
    }
    size_t num_elements = data_size / sizeof(uint16_t);

    dst = aligned_alloc(32, data_size);
    src1 = aligned_alloc(32, data_size);
    src2 = aligned_alloc(32, data_size);

    for (size_t idx = 0; idx < num_elements; ++idx) {
        src1[idx] = (uint16_t)(rand() % 65536);
        src2[idx] = (uint16_t)(rand() % 65536);
    }

    mask = 0xFFFF;
    w = (int)(num_elements - (num_elements % 4));
}