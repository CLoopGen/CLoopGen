#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

typedef char *png_charp;

png_charp key;
png_charp text;

static char *data_buffer;

void init_vars() {
    size_t data_size = 64 << 20; // 64 MB to target ~0.01 sec runtime on modern CPU
    data_buffer = (char *)malloc(data_size);
    if (!data_buffer) {
        exit(1);
    }

    // Fill with non-zero bytes so that the loop runs through most of the buffer
    memset(data_buffer, 'a', data_size - 1);
    data_buffer[data_size - 1] = '\0'; // null-terminate to stop the loop

    key = data_buffer;
    text = NULL;
}

__attribute__((destructor))
static void cleanup() {
    free(data_buffer);
}