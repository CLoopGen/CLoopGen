#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

char *src;
char *s;
char *win32_send;
char *r;

static char *input_buffer;
static char *output_buffer;
static size_t input_size;
static size_t output_capacity;

void init_vars() {
    input_size = 1 << 20; // 1 MB of input data

    input_buffer = (char *)malloc(input_size);
    if (!input_buffer) {
        fprintf(stderr, "Failed to allocate input buffer\n");
        exit(1);
    }

    // Initialize input: mix of normal and special characters
    for (size_t i = 0; i < input_size; i++) {
        char c = rand() % 95 + 32; // printable ASCII
        if (c == '\'' || c == '\\') {
            if (rand() % 2) c = 'x'; // reduce frequency of specials
        }
        input_buffer[i] = c;
    }
    // Ensure some occurrences of special characters
    input_buffer[0] = '\'';
    input_buffer[input_size / 2] = '\\';
    input_buffer[input_size - 1] = '\'';

    src = input_buffer;
    win32_send = input_buffer + input_size;

    // Output buffer must be large enough: worst case every char is escaped (doubled)
    output_capacity = 2 * input_size;
    output_buffer = (char *)malloc(output_capacity);
    if (!output_buffer) {
        fprintf(stderr, "Failed to allocate output buffer\n");
        free(input_buffer);
        exit(1);
    }
    r = output_buffer;
}

__attribute__((constructor))
static void initialize() {
    init_vars();
}