#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char start_color[4096];
char *p;

static char data_buffer[256 * 1024 * 1024]; // 256 MB buffer to ensure ~0.01 sec runtime

void init_vars() {
    // Initialize start_color as a pointer into the large data buffer
    // We'll set up the buffer so that it contains a long sequence of non-'-', non-'\0', and '(' ... ')' patterns
    // Ensure p will traverse a significant portion (~tens of millions of chars) before stopping

    char *buf = data_buffer;
    size_t total_size = sizeof(data_buffer);
    size_t pos = 0;

    // Fill most of the buffer with 'X' to simulate normal traversal
    while (pos < total_size - 256 * 1024) { // Leave room at the end
        if (rand() % 1000 == 0) {
            // Occasionally insert a parenthesized group: "(...)"
            buf[pos++] = '(';
            int len = 1 + rand() % 32; // Random length inside
            for (int i = 0; i < len && pos < total_size - 1; i++) {
                buf[pos++] = 'A' + (rand() % 26);
            }
            if (pos < total_size) {
                buf[pos++] = ')';
            }
        } else {
            buf[pos++] = 'X';
        }
    }

    // Near the end, place a '-' to terminate the outer loop
    buf[pos++] = '-';

    // Ensure null termination somewhere after, though loop should break on '-'
    if (pos < total_size) {
        buf[pos] = '\0';
    }

    // Initialize start_color as first 4096 bytes of this buffer
    memcpy(start_color, buf, 4096);

    // Initialize p to point to start_color initially (will be updated in loop)
    p = start_color;
}