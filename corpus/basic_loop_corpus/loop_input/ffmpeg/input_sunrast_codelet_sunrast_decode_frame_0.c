#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *buf;
unsigned int x;
uint8_t *ptr;
unsigned int len;

static uint8_t *internal_buf;
static uint32_t *internal_ptr;

void init_vars() {
    len = 64 * 1024 * 1024; // 64 million iterations -> ~64MB input, ~256MB total data access

    internal_buf = (uint8_t*)aligned_alloc(32, 3 * len * sizeof(uint8_t));
    if (!internal_buf) exit(1);
    for (size_t i = 0; i < 3 * len; i++) {
        internal_buf[i] = (uint8_t)(i & 0xFF);
    }

    internal_ptr = (uint32_t*)aligned_alloc(32, (len + 1) * 4 * sizeof(uint32_t));
    if (!internal_ptr) exit(1);

    buf = internal_buf;
    ptr = (uint8_t*)internal_ptr;
    x = 0;
}

__attribute__((destructor))
void cleanup() {
    if (internal_buf) free(internal_buf);
    if (internal_ptr) free(internal_ptr);
}