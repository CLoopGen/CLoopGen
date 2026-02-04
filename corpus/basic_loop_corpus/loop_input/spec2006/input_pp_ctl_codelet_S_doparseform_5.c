#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *s;
char *win32_send;
char *base;
int maxops;

static char *data_buffer;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU
    data_buffer = (char *)malloc(data_size);
    if (!data_buffer) {
        data_size = 16 * 1024 * 1024; // Fallback to 16 MB
        data_buffer = (char *)malloc(data_size);
    }

    // Initialize buffer with mostly printable chars, include some '\n', '@', '^'
    for (size_t i = 0; i < data_size; i++) {
        int r = rand() % 256;
        if (r < 2) data_buffer[i] = '\n';
        else if (r < 4) data_buffer[i] = '@';
        else if (r < 6) data_buffer[i] = '^';
        else data_buffer[i] = 'A' + (r % 26);
    }

    s = data_buffer;
    win32_send = data_buffer + data_size - 1;
    base = NULL;
    maxops = 0;
}