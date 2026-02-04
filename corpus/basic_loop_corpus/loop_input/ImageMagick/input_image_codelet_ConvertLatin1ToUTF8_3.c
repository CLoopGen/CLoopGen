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
static size_t data_size;

void init_vars() {
    data_size = 128 * 1024 * 1024; // 128 MB
    data_buffer = malloc(data_size);
    if (!data_buffer) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    for (size_t i = 0; i < data_size - 1; i++) {
        data_buffer[i] = rand() % 256;
    }
    data_buffer[data_size - 1] = '\x00'; // Ensure null terminator at the end

    content = data_buffer;
    p = content;
    length = 0;
}