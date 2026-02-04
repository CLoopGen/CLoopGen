#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *label;
size_t number_lines;

static char *data_buffer;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB to target ~0.01 sec runtime
    data_buffer = (char *)malloc(data_size);
    if (!data_buffer) {
        exit(1);
    }

    // Fill buffer with printable characters and newlines
    for (size_t i = 0; i < data_size - 1; i++) {
        if (rand() % 32 == 0) {
            data_buffer[i] = '\n';
        } else {
            data_buffer[i] = 'a' + (rand() % 26);
        }
    }
    data_buffer[data_size - 1] = '\x00'; // Null-terminate

    label = data_buffer;
    number_lines = 0; // Will be incremented starting from 1 in loop
}

__attribute__((destructor))
static void cleanup() {
    free(data_buffer);
}