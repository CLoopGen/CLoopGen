#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

typedef size_t STRLEN;

char *attrstr;
STRLEN len;

static char *buffer;

void init_vars() {
    const size_t input_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU
    buffer = (char *)malloc(input_size);
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Fill buffer with leading whitespace to ensure loop runs through many iterations
    size_t num_whitespace = input_size - 1;
    memset(buffer, ' ', num_whitespace);
    buffer[num_whitespace] = 'A'; // Non-whitespace to break the loop condition
    buffer[num_whitespace + 1] = '\0';

    // Initialize external variables
    attrstr = buffer;
    len = input_size;
}