#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int size;
ptrdiff_t stride;
uint8_t *src;
uint8_t *left;

static uint8_t *src_buffer;
static uint8_t *left_buffer;

void init_vars() {
    size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec on typical modern CPU
    stride = 1;
    src_buffer = (uint8_t*)aligned_alloc(32, size + 1);
    left_buffer = (uint8_t*)aligned_alloc(32, size);
    if (!src_buffer || !left_buffer) {
        exit(1);
    }
    src = src_buffer + 1; // Base such that index (-1) is valid at first access
    left = left_buffer;
}

__attribute__((constructor))
static void constructor_call() {
    init_vars();
}