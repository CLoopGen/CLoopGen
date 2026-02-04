#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *d;
ptrdiff_t stride;
int y;
uint64_t a;

static uint8_t *allocated_buffer;

void init_vars() {
    size_t total_size = 1 << 20; // 1 MB
    stride = sizeof(uint64_t);
    allocated_buffer = aligned_alloc(64, total_size);
    d = allocated_buffer;
    a = 0xdeadbeefdeadbeefULL;
}

__attribute__((destructor))
static void cleanup() {
    free(allocated_buffer);
}