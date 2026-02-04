#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *w;
static char *data_buffer;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB to target ~0.01 sec runtime
    data_buffer = (char *)malloc(data_size);
    if (!data_buffer) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    // Fill buffer with whitespace and non-whitespace to ensure loop runs meaningfully
    size_t i;
    for (i = 0; i < data_size - 1; i++) {
        data_buffer[i] = ' '; // Most are spaces to make loop iterate
    }
    data_buffer[data_size - 1] = 'a'; // Ensure null terminator is not immediately hit
    data_buffer[data_size] = '\0';    // Null terminate

    w = data_buffer; // Initialize external pointer
}

__attribute__((constructor))
static void constructor_init() {
    init_vars();
}

__attribute__((destructor))
static void destructor_free() {
    free(data_buffer);
}