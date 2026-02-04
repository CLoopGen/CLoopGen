#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned int length;
char *dest;
char *source;

static char *source_buffer;
static char *dest_buffer;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64 MB for ~0.01 sec on modern CPU

    source_buffer = (char *)calloc(data_size, sizeof(char));
    dest_buffer = (char *)calloc(data_size, sizeof(char));

    if (!source_buffer || !dest_buffer) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; ++i) {
        source_buffer[i] = (char)(i & 0xFF);
    }

    source = source_buffer;
    dest = dest_buffer;
    length = (unsigned int)data_size;
}