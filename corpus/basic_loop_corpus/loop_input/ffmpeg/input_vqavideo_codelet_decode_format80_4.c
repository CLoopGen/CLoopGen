#include <stdlib.h>
#include <string.h>

unsigned char *dest;
int dest_index;
int count;
int src_pos;
int i;

void init_vars() {
    // Allocate approximately 64MB of data to ensure loop runs ~0.01 seconds on modern CPUs
    size_t data_size = 64 * 1024 * 1024;
    dest = (unsigned char*)malloc(data_size);
    
    // Initialize parameters to ensure valid memory access
    dest_index = 32 * 1024 * 1024;  // Middle of allocated buffer
    src_pos = 1024;                 // Positive offset within bounds
    count = 16 * 1024;              // Copy 16KB of data
    
    // Ensure we don't go out of bounds
    // dest[dest_index + i] must be valid for i in [0, count)
    // dest[dest_index - src_pos + i] must be valid for i in [0, count)
    // So: dest_index + count <= data_size
    // And: dest_index - src_pos >= 0 and dest_index - src_pos + count <= data_size
    if (dest_index + count >= data_size) {
        dest_index = data_size - count - 1;
    }
    if (src_pos > dest_index) {
        src_pos = dest_index / 2;
    }
    
    // Initialize source region with some data
    for (int j = 0; j < count + src_pos; j++) {
        dest[dest_index - src_pos + j] = (unsigned char)(j & 0xFF);
    }
}