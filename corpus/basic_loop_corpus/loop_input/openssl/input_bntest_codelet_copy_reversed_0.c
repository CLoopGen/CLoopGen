#include <inttypes.h>
#include <stdlib.h>

uint8_t *dst;
uint8_t *src;
size_t len;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    len = 512 * 1024; // 512 KB for ~0.01 sec runtime on modern CPU

    src_buffer = (uint8_t*)malloc(len);
    dst_buffer = (uint8_t*)malloc(len);

    if (!src_buffer || !dst_buffer) {
        // Ensure allocation succeeded; minimal error handling for standalone use
        while(1); // Prevent undefined behavior if malloc fails
    }

    // Initialize src data to avoid garbage, and set initial pointers
    for (size_t i = 0; i < len; i++) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
    }

    src = src_buffer;
    dst = dst_buffer + len - 1; // point to last element initially
}