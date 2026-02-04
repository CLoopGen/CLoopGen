#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef unsigned char U8;

U8 *s;
U8 *win32_send;

static U8 *data_buffer;
static size_t data_size = 1 << 20; // 1MB for ~0.01 sec runtime on modern CPU

void init_vars() {
    if (data_buffer != NULL) return; // Prevent multiple initializations

    data_buffer = (U8 *)malloc(data_size);
    if (!data_buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize buffer with mixed lowercase and other characters
    for (size_t i = 0; i < data_size; i++) {
        data_buffer[i] = (U8)((rand() % 128));
    }

    s = data_buffer;
    win32_send = data_buffer + data_size;
}