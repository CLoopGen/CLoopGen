#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

uint8_t *in;
uint64_t v0;
uint64_t v1;
uint64_t v2;
uint64_t v3;
uint64_t m;
uint8_t *end;

static uint8_t *buffer;
static size_t buffer_size = 1 << 20; // 1MB data for ~0.01 sec runtime estimate

void init_vars() {
    // Allocate buffer with at least 1MB, aligned to 8 bytes
    buffer = aligned_alloc(8, buffer_size);
    if (!buffer) {
        exit(1);
    }

    // Initialize buffer with non-zero data to ensure meaningful computation
    for (size_t i = 0; i < buffer_size; ++i) {
        buffer[i] = (uint8_t)(i & 0xFF);
    }

    // Set in to start of buffer
    in = buffer;

    // Set end to just past the last full 8-byte block
    end = buffer + (buffer_size / 8) * 8;

    // Initialize hash state variables
    v0 = 0x736f6d6570736575ULL;
    v1 = 0x646f72616e646f6dULL;
    v2 = 0x6c7967656e657261ULL;
    v3 = 0x7465646279746573ULL;
}