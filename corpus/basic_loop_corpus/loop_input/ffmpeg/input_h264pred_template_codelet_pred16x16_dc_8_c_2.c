#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

ptrdiff_t stride;
int i;
int dc;
uint8_t *src;

static uint8_t *src_buffer;

void init_vars() {
    // Allocate a buffer large enough to allow accesses with stride and index up to 15
    // We access src[-1 + i*stride] for i from 0 to 15 -> max index used: -1 + 15*stride
    // So we need at least 15*stride bytes past the effective start, plus one for the -1 offset.
    // We'll choose a stride that makes total data about 64MB for realistic timing (~0.01 sec)
    
    size_t total_data_size = 64 * 1024 * 1024; // ~64 MB
    stride = total_data_size / 16; // ensures we cover most of the buffer
    
    // Allocate extra space so that src[-1] is valid (we'll place src at offset 1)
    src_buffer = (uint8_t*)aligned_alloc(32, total_data_size + 32);
    if (!src_buffer) abort();
    
    // Initialize buffer with non-zero values to make accumulation meaningful
    for (size_t j = 0; j < total_data_size + 32; j++) {
        src_buffer[j] = (uint8_t)(j % 251);
    }
    
    // Set src so that src[-1] points to a valid byte in our buffer
    src = src_buffer + 1;
    
    // Initialize dc to zero for predictable accumulation
    dc = 0;
}