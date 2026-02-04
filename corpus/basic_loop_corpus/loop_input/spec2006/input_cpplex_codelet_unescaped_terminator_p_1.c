#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned char *dest;
unsigned char *start;
unsigned char *temp;

static unsigned char *data_buffer;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU
    data_buffer = (unsigned char *)calloc(data_size, sizeof(unsigned char));
    
    if (!data_buffer) {
        exit(1);
    }

    // Fill buffer with backslashes to ensure loop runs through many iterations
    memset(data_buffer, '\\', data_size);

    // Set start to beginning of buffer
    start = data_buffer;
    // Set dest to end of buffer
    dest = data_buffer + data_size - 1;
    // Initialize temp to dest, ensuring it can go backwards while checking temp[-1]
}