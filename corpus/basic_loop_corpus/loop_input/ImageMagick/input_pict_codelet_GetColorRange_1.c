#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

char start_color[262144]; // 256KB buffer to ensure ~0.01s runtime
char *p;

void init_vars() {
    // Initialize start_color with a pattern that includes '(' and ')' pairs and ends with '-'
    size_t pos = 0;
    const size_t max_size = sizeof(start_color) - 32; // Leave room for terminator

    while (pos < max_size - 10) {
        // Randomly decide to insert a parenthesized block or plain characters
        if (rand() % 3 == 0 && pos + 10 < max_size) {
            start_color[pos++] = '(';
            // Fill inside with non-')' chars
            for (int i = 0; i < rand() % 15 + 1; i++) {
                if (pos >= max_size) break;
                start_color[pos++] = 'a' + (rand() % 26);
            }
            if (pos < max_size) {
                start_color[pos++] = ')';
            }
        } else {
            if (pos < max_size) {
                start_color[pos++] = 'a' + (rand() % 26);
            }
        }
    }

    // Ensure we don't exceed buffer - replace last few with proper termination
    // Place '-' near the end but not at the very end to avoid boundary issues
    if (pos >= sizeof(start_color) - 2) {
        pos = sizeof(start_color) - 3;
    }
    start_color[pos] = '-';
    start_color[pos + 1] = '\0';

    // Initialize p to start of array
    p = start_color;
}