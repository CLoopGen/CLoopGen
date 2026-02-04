#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

uint8_t *src;
ptrdiff_t stride;
uint8_t *cm;
uint8_t *top;
int y;

static uint8_t *src_buffer;
static uint8_t *cm_buffer;
static uint8_t *top_buffer;

void init_vars() {
    const size_t data_size = 16 * 1024 * 1024; // ~16MB for sufficient runtime (~0.01s target)

    // Allocate buffers with proper alignment and size
    src_buffer = aligned_alloc(32, data_size);
    cm_buffer = aligned_alloc(32, 512);
    top_buffer = aligned_alloc(32, 16);

    // Initialize all to zero for predictable behavior
    memset(src_buffer, 0, data_size);
    memset(cm_buffer, 0, 512);
    memset(top_buffer, 0, 16);

    // Initialize lookup table cm: map each index to a clamped value (0-255)
    for (int i = 0; i < 512; i++) {
        cm_buffer[i] = (uint8_t)(i < 256 ? i : 255);
    }

    // Fill top with valid indices (0-255) to avoid out-of-bounds in cm lookup
    for (int i = 0; i < 8; i++) {
        top_buffer[i] = i * 31; // Spread indices across range
    }

    // Set globals
    src = src_buffer + 1; // Leave room for src[-1]
    stride = 8;           // Advance by 8 bytes per row
    cm = cm_buffer;
    top = top_buffer;
}

// Ensure initialization happens before loop is called
__attribute__((constructor)) void auto_init() {
    init_vars();
}