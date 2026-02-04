#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *top;
uint8_t *left;
int i;
uint8_t v[22];

static uint8_t *alloc_uint8_array(size_t size) {
    uint8_t *ptr = (uint8_t *)calloc(size, sizeof(uint8_t));
    if (!ptr) exit(1);
    for (size_t i = 0; i < size; i++) {
        ptr[i] = (uint8_t)(i & 0xFF);
    }
    return ptr;
}

void init_vars() {
    top = alloc_uint8_array(1024 * 1024);
    left = alloc_uint8_array(1024 * 1024);
    for (int i = 0; i < 22; i++) {
        v[i] = 0;
    }
    i = 0;
}