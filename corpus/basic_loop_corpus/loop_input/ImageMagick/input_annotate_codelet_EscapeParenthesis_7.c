#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

char *source;
char *q;
char *p;

static char *buffer_source;
static char *buffer_q;

void init_vars() {
    size_t input_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU

    buffer_source = (char*)malloc(input_size);
    if (!buffer_source) exit(1);

    // Fill source with mixed printable characters and escape sequences
    for (size_t i = 0; i < input_size - 1; i++) {
        int r = rand() % 100;
        if (r < 3) buffer_source[i] = '\\';
        else if (r < 6) buffer_source[i] = '(';
        else if (r < 9) buffer_source[i] = ')';
        else buffer_source[i] = 'a' + (r % 26);
    }
    buffer_source[input_size - 1] = '\x00'; // null terminate

    // Allocate output buffer: worst case doubles in size (every char escaped)
    size_t output_size = 2 * input_size;
    buffer_q = (char*)malloc(output_size);
    if (!buffer_q) exit(1);

    // Initialize pointers
    source = buffer_source;
    q = buffer_q;
}