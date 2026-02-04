#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *a;
ptrdiff_t s;
int i;
int j;
int var;

static uint8_t *buffer;
static size_t buffer_size = 1 << 20; // 1MB

void init_vars() {
    s = 64;
    var = 0;

    buffer = (uint8_t*)calloc(buffer_size, sizeof(uint8_t));
    if (!buffer) {
        exit(1);
    }

    a = buffer;

    for (size_t idx = 0; idx < buffer_size; ++idx) {
        buffer[idx] = rand() & 0xFF;
    }
}