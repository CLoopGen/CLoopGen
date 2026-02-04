#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *block;
ptrdiff_t stride;
int height;
int y;

static uint8_t *allocated_memory;

void init_vars() {
    height = 1000000 / 8; // Adjust height for approximate 0.01s runtime
    stride = 8;
    size_t total_size = (size_t)height * (size_t)stride;

    allocated_memory = calloc(total_size, 1);
    if (!allocated_memory) {
        exit(1);
    }

    block = allocated_memory;
}

__attribute__((destructor))
static void cleanup() {
    free(allocated_memory);
}