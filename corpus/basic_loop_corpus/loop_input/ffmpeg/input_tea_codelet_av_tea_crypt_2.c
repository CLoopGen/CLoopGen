#include <stdlib.h>
#include <stdint.h>

uint8_t *dst;
uint8_t *src;
uint8_t *iv;
int i;

static uint8_t *alloc_and_init(size_t size) {
    uint8_t *ptr = (uint8_t *)malloc(size);
    if (!ptr) exit(1);
    for (size_t i = 0; i < size; i++)
        ptr[i] = rand() & 0xFF;
    return ptr;
}

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime
    dst = alloc_and_init(data_size);
    src = alloc_and_init(data_size);
    iv = alloc_and_init(data_size);
    i = 0;
}