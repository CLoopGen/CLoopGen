#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char start_color[4096];
char *p;

void init_vars() {
    // Initialize the start_color array with a pattern that will cause realistic traversal
    // Mix of normal characters, parentheses, and termination conditions
    size_t total_size = 2 * 1024 * 1024; // ~2MB data to target ~0.01 sec runtime on modern CPU
    static char buffer[2 * 1024 * 1024];

    size_t idx = 0;
    while (idx < total_size - 100) {
        // Randomly add either plain text or parenthesized group
        if (rand() % 3 == 0) {
            buffer[idx++] = '(';
            int depth = 1;
            while (depth && idx < total_size - 10) {
                if (rand() % 20 == 0) {
                    buffer[idx++] = ')';
                    depth--;
                } else if (rand() % 15 == 0) {
                    buffer[idx++] = '(';
                    depth++;
                } else {
                    buffer[idx++] = 'a' + (rand() % 26);
                }
            }
            // Ensure we don't go too deep
            while (depth-- > 0 && idx < total_size - 1)
                buffer[idx++] = ')';
        } else {
            // Add regular characters
            int len = rand() % 16 + 1;
            for (int i = 0; i < len && idx < total_size - 1; i++) {
                char c;
                int r = rand() % 100;
                if (r < 2) c = '-';
                else if (r < 5) c = '\0';
                else c = 'a' + (rand() % 26);
                buffer[idx++] = c;
                if (c == '-' || c == '\0') break;
            }
            if (buffer[idx-1] == '-' || buffer[idx-1] == '\0')
                continue;
        }
    }

    // Guarantee final termination with null
    buffer[total_size - 1] = '\0';

    // Copy into repeated blocks to fill start_color as needed
    for (int i = 0; i < 4096; i++) {
        start_color[i] = buffer[i % total_size];
    }

    // Initialize pointer p to point to start of array
    p = start_color;
}