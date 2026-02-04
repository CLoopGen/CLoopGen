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
static size_t total_size_d;
static size_t total_size_top;
static size_t total_size_left;

void init_vars() {
    total_size_d = 1 << 20;
    total_size_top = 10;
    total_size_left = 10;

    d_storage = (uint8_t*)calloc(total_size_d, sizeof(uint8_t));
    top_storage = (uint8_t*)calloc(total_size_top, sizeof(uint8_t));
    left_storage = (uint8_t*)calloc(total_size_left, sizeof(uint8_t));

    if (!d_storage || !top_storage || !left_storage) {
        exit(1);
    }

    d = d_storage;
    top = top_storage + 1;
    left = left_storage + 1;

    stride = (ptrdiff_t)(total_size_d / 8);

    for (size_t i = 0; i < total_size_top; i++) {
        top_storage[i] = (uint8_t)((i * 7 + 13) % 251);
    }
    for (size_t i = 0; i < total_size_left; i++) {
        left_storage[i] = (uint8_t)((i * 11 + 17) % 251);
    }
    for (size_t i = 0; i < total_size_d; i++) {
        d_storage[i] = (uint8_t)((i * 3 + 7) % 251);
    }
}