#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

int dialect_number;
char *p;
int i;

static char *data_buffer;

void init_vars() {
    const size_t buffer_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime
    data_buffer = (char*)malloc(buffer_size);
    if (!data_buffer) {
        exit(1);
    }

    // Fill buffer with patterns of fields separated by '|'
    size_t pos = 0;
    const size_t field_size = 128;
    while (pos + field_size + 1 < buffer_size) {
        memset(data_buffer + pos, 'a', field_size);
        data_buffer[pos + field_size] = '|';
        pos += field_size + 1;
    }
    data_buffer[buffer_size - 1] = '\0'; // Ensure null terminator

    // Initialize external variables
    dialect_number = 50000; // Adjusted to ensure loop runs within buffer bounds and target time
    p = data_buffer;
}

__attribute__((destructor))
static void cleanup() {
    free(data_buffer);
}