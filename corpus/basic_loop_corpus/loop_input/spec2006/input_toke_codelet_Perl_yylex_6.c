#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *s;
char *t;

static char data[131072]; // 128KB of input data

void init_vars() {
    // Initialize a large buffer with leading whitespace
    size_t size = sizeof(data) - 1; // Leave space for null terminator
    memset(data, ' ', size / 3);
    memset(data + size / 3, '\t', size / 3);
    memset(data + 2 * size / 3, '\r', size / 3);
    // Fill the rest with non-whitespace to terminate the loop
    if (size > 2 * size / 3) {
        memset(data + 2 * size / 3 + size / 3, 'a', size - 2 * size / 3 - size / 3);
    }
    data[size] = '\0';

    // Assign s to point to the data buffer
    s = data;

    // Ensure t is initialized by the loop itself, but we can set it here if needed
    // However, loop will reassign t = s, so no need to initialize t here
}