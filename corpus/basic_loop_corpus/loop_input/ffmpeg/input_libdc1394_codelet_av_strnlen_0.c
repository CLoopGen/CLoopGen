#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char *s;
size_t len;
size_t i;

static char *internal_buffer = NULL;

void init_vars() {
    // Allocate approximately 64MB to ensure loop runs about 0.01 seconds
    // on a modern CPU assuming memory-bound execution
    size_t data_size = 64 * 1024 * 1024;
    internal_buffer = (char *)malloc(data_size);
    
    if (!internal_buffer) {
        exit(1);
    }
    
    // Fill most of the buffer with non-zero bytes
    memset(internal_buffer, 'A', data_size - 1);
    
    // Place a null terminator near the end to trigger loop exit
    // This ensures that s[i] becomes 0 within bounds
    internal_buffer[data_size - 1] = '\0';
    
    // Set external variables
    s = internal_buffer;
    len = data_size;
    i = 0;
}

// Cleanup function to avoid memory leaks (not required but good practice)
void cleanup_vars() {
    if (internal_buffer) {
        free(internal_buffer);
        internal_buffer = NULL;
    }
}