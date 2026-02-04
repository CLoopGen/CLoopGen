#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char start_color[262144]; // 256KB buffer to ensure ~0.01s runtime
char *p;

void init_vars() {
    // Initialize start_color with data that ensures realistic loop behavior
    // Pattern: text with embedded (parenthesized sections) and ends with '-'
    size_t pos = 0;
    const size_t max_size = sizeof(start_color) - 256; // Leave room for null and safety

    while (pos < max_size) {
        // Add normal characters
        for (int i = 0; i < 50 && pos < max_size; ++i) {
            if (rand() % 100 < 90) {
                start_color[pos++] = 'a' + (rand() % 26);
            } else {
                // Insert a parenthesized section
                start_color[pos++] = '(';
                for (int j = 0; j < 15 && pos < max_size; ++j) {
                    start_color[pos++] = 'A' + (rand() % 26);
                }
                start_color[pos++] = ')';
            }
        }
    }

    // Ensure we don't exceed buffer
    if (pos >= sizeof(start_color) - 1) {
        pos = sizeof(start_color) - 2;
    }

    // Terminate with '-' to stop outer loop cleanly
    start_color[pos] = '-';
    start_color[pos + 1] = '\x00'; // Null terminator as backup
}