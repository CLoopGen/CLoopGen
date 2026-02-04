#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

uint8_t *block;
ptrdiff_t stride;
int height;
int y;

static uint8_t *allocated_memory;

void init_vars() {
    height = 1048576; // 1MB of data
    stride = 256;
    allocated_memory = (uint8_t*)aligned_alloc(32, (size_t)height * (size_t)stride);
    if (!allocated_memory) exit(1);
    block = allocated_memory;
    y = 0;
}