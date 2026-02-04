#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char *s;
size_t len;
size_t i;

static char *buffer;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU
    buffer = (char*)malloc(data_size);
    if (!buffer) {
        exit(1);
    }
    
    // Fill most of the buffer with non-zero bytes
    memset(buffer, 'x', data_size - 1);
    
    // Place a null terminator near the end to control loop termination
    buffer[data_size - 1] = '\0';
    
    s = buffer;
    len = data_size;
}