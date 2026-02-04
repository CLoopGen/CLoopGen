#include <stdlib.h>
#include <stdint.h>

uint8_t *src;
int32_t stride;
uint8_t lpcnt;

static uint8_t *buffer;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime estimate
    buffer = (uint8_t *)aligned_alloc(32, data_size);
    if (!buffer) exit(1);

    src = buffer;
    stride = 16;
}