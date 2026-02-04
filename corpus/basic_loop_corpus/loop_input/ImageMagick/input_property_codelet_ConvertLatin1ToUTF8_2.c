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

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU
    data_buffer = (unsigned char *)malloc(data_size);
    if (!data_buffer) {
        exit(1);
    }

    // Initialize buffer with random-like data, ensuring a null terminator at the end
    for (size_t i = 0; i < data_size - 1; i++) {
        data_buffer[i] = rand() & 0xFF;
    }
    data_buffer[data_size - 1] = '\x00'; // Null terminator to stop the loop

    // Initialize external pointers and variables
    content = data_buffer;
    p = NULL; // Will be set in loop()
    length = 0;
}

__attribute__((destructor))
static void cleanup() {
    free(data_buffer);
}