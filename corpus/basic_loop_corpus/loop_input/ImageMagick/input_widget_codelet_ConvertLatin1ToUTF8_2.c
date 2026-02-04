#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

unsigned char *restrict content;
unsigned char *restrict p;
size_t length;

static unsigned char *content_storage;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU
    content_storage = malloc(data_size);
    if (!content_storage) {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }

    // Initialize with random data, ensuring a null terminator at the end
    for (size_t i = 0; i < data_size - 1; i++) {
        content_storage[i] = rand() & 0xFF;
    }
    content_storage[data_size - 1] = '\x00'; // Null terminator

    content = content_storage;
    p = content;
    length = 0;
}