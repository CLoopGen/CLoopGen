#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

unsigned char *restrict content;
unsigned char *restrict p;
size_t length;

static unsigned char *content_buffer;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU

    content_buffer = malloc(data_size);
    if (!content_buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize buffer with random data, ensuring a null terminator at the end
    for (size_t i = 0; i < data_size - 1; i++) {
        content_buffer[i] = rand() & 0xFF;
    }
    content_buffer[data_size - 1] = '\x00'; // Ensure loop termination

    content = content_buffer;
    p = content;
    length = 0;
}

__attribute__((destructor))
static void cleanup() {
    free(content_buffer);
}