#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
uint8_t *iv;
int i;

static uint8_t *alloc_initialized_array(size_t size) {
    uint8_t *arr = aligned_alloc(32, size);
    for (size_t i = 0; i < size; i++) {
        arr[i] = rand() & 0xFF;
    }
    return arr;
}

void init_vars() {
    const size_t data_size = 128 * 1024 * 1024; // 128 MB for ~0.01 sec runtime on modern CPU
    dst = alloc_initialized_array(data_size);
    src = alloc_initialized_array(data_size);
    iv  = alloc_initialized_array(data_size);
    i = 0;
}