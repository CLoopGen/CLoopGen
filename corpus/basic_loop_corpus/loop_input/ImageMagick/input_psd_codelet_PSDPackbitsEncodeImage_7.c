#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t length;
unsigned char *pixels;
int count;
ssize_t i;
ssize_t j;
unsigned char *q;
unsigned char *packbits;

unsigned char *pixels_buffer;
unsigned char *q_buffer;
unsigned char *packbits_buffer;

void init_vars() {
    // Set up data size to make loop run about 0.01 seconds
    // Based on typical performance, ~32MB input tends to take ~0.01s for this kind of processing
    length = 32 * 1024 * 1024;
    
    // Allocate buffers with padding to prevent out-of-bounds access
    pixels_buffer = (unsigned char*)aligned_alloc(64, length + 128);
    q_buffer = (unsigned char*)aligned_alloc(64, length * 2); // worst-case growth
    packbits_buffer = (unsigned char*)aligned_alloc(64, 130); // max packbits size

    // Initialize pixel data with a pattern that triggers both RLE and literal modes
    for (size_t idx = 0; idx < length; ++idx) {
        if (idx % 128 < 32) {
            // Run-length encoded regions (same value)
            pixels_buffer[idx] = 42;
        } else {
            // Non-repeating sequences
            pixels_buffer[idx] = (unsigned char)(idx % 251);
        }
    }

    // Initialize pointers
    pixels = pixels_buffer;
    q = q_buffer;
    packbits = packbits_buffer;

    // Initialize other variables
    count = 0;
    i = (ssize_t)length;
    j = 0;

    // Ensure packbits[0..128] is initialized
    for (int k = 0; k < 129; k++) {
        packbits[k] = 0;
    }
}