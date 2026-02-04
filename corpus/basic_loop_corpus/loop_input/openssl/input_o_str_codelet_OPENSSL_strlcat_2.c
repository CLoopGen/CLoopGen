#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *dst;
size_t size;
size_t l;

static char data_buffer[1024 * 128]; // 128KB buffer

void init_vars() {
    // Initialize the buffer with non-null characters, null-terminated at the end
    memset(data_buffer, 'A', sizeof(data_buffer) - 1);
    data_buffer[sizeof(data_buffer) - 1] = '\0';
    
    // Initialize dst to point to the beginning of the buffer
    dst = data_buffer;
    
    // Initialize size to the full buffer size (including the null terminator)
    size = sizeof(data_buffer);
    
    // Initialize l to 0
    l = 0;
}