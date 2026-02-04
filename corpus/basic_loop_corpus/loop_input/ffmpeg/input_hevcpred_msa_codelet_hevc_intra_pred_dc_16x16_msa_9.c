#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
int32_t stride;
uint32_t row;

static uint8_t *buffer;

void init_vars() {
    stride = 65536;
    buffer = (uint8_t*)aligned_alloc(32, stride * 16);
    if (!buffer) exit(1);
    dst = buffer;
}

__attribute__((destructor))
static void cleanup() {
    free(buffer);
}