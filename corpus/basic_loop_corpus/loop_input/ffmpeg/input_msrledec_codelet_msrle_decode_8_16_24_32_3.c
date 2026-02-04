#include <stdint.h>
#include <stdlib.h>

uint8_t *output;
int p1;
int i;
uint32_t pix32;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB to target ~0.01s runtime
    output = (uint8_t *)aligned_alloc(4, data_size);
    if (!output) exit(1);
    p1 = data_size / 4;
    pix32 = 0xDEADBEEF;
}