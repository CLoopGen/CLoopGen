#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef unsigned char U8;

U8 *s;
U8 *win32_send;

static U8 *buffer;
static size_t data_size = 1 << 20; // 1MB for ~0.01 sec runtime

void init_vars() {
    buffer = (U8*)malloc(data_size);
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize buffer with mixed-case ASCII data
    for (size_t i = 0; i < data_size; i++) {
        buffer[i] = (U8)('A' + (i % 64)); // Covers 'A'-'Z', 'a'-z', and others
    }

    s = buffer;
    win32_send = buffer + data_size;
}