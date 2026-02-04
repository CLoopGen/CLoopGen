#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ch;

static int8_t top_storage[256 * 1024]; // 256KB data
static int8_t left_storage[256 * 1024]; // 256KB data

int8_t *const top = top_storage;
int8_t *const left = left_storage;

void init_vars() {
    for (size_t i = 0; i < sizeof(top_storage); ++i) {
        top_storage[i] = (int8_t)(i & 0xFF);
    }
    for (size_t i = 0; i < sizeof(left_storage); ++i) {
        left_storage[i] = (int8_t)((i * 3) & 0xFF);
    }
}