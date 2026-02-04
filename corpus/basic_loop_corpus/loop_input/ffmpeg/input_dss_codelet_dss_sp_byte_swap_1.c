#include <stdlib.h>
#include <stdint.h>

uint8_t *dst;
uint8_t *src;
int i;

void init_vars() {
    size_t data_size = 256 * 1024 * 1024; // 256 MB
    src = (uint8_t*)malloc(data_size);
    dst = (uint8_t*)malloc(data_size);

    if (!src || !dst) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        src[idx] = (uint8_t)(idx & 0xFF);
        dst[idx] = 0;
    }
}