#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *d;
uint8_t *top;
uint8_t *left;
ptrdiff_t stride;
int x;
int y;

static uint8_t *d_storage;
static uint8_t *top_storage;
static uint8_t *left_storage;
static size_t total_size = 1 << 20; // 1MB for reasonable runtime (~0.01 sec)

void init_vars() {
    d_storage = calloc(total_size, sizeof(uint8_t));
    top_storage = calloc(256, sizeof(uint8_t));
    left_storage = calloc(256, sizeof(uint8_t));

    if (!d_storage || !top_storage || !left_storage) {
        exit(1);
    }

    d = d_storage;
    top = top_storage;
    left = left_storage;
    stride = 64; 

    for (size_t i = 0; i < 256; i++) {
        top[i] = (uint8_t)(i * 31);
        left[i] = (uint8_t)(i * 17);
    }
}