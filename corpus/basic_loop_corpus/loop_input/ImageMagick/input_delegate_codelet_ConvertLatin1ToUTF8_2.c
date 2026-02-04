#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

unsigned char *restrict content;
unsigned char *restrict p;
size_t length;

static unsigned char *data_buffer;
static size_t data_size = 1 << 20; // 1MB

void init_vars() {
    if (data_buffer) return; // Prevent reinitialization
    
    data_buffer = (unsigned char*)malloc(data_size);
    if (!data_buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    // Initialize buffer with random data but ensure a null terminator at the end
    for (size_t i = 0; i < data_size - 1; i++) {
        data_buffer[i] = rand() & 0xFF;
    }
    data_buffer[data_size - 1] = '\x00'; // Ensure loop termination
    
    content = data_buffer;
    p = content;
    length = 0;
}

// Cleanup function to avoid memory leaks (not called here but good practice)
void cleanup_vars() {
    free(data_buffer);
    data_buffer = NULL;
}