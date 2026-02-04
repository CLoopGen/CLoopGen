#include <stdint.h>
#include <stdlib.h>

int32_t stride;
uint8_t *tmp_dst;
uint32_t row;

static uint8_t *buffer;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB for sufficient runtime (~0.01 sec)
    buffer = (uint8_t*)aligned_alloc(64, data_size);
    if (!buffer) exit(1);

    stride = 64; 
    tmp_dst = buffer;
}