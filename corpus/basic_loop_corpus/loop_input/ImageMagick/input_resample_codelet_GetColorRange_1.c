#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char start_color[1 << 20]; // 1MB buffer
char *p;

void init_vars() {
    // Initialize the buffer with a pattern that ensures realistic traversal
    size_t pos = 0;
    const size_t max_size = sizeof(start_color) - 256; // Leave room for null terminator and safety

    while (pos < max_size) {
        int r = rand() % 100;

        if (r < 70) {
            // Regular character
            start_color[pos++] = 'a' + (rand() % 26);
        } else if (r < 85) {
            // Open parenthesis, followed by some content and closing
            start_color[pos++] = '(';
            int depth = 1;
            while (depth > 0 && pos < max_size) {
                if ((rand() % 10) == 0) {
                    start_color[pos++] = ')';
                    depth--;
                } else if ((rand() % 15) == 0 && depth < 5) {
                    start_color[pos++] = '(';
                    depth++;
                } else {
                    start_color[pos++] = 'a' + (rand() % 26);
                }
            }
        } else if (r < 90) {
            // Insert '-' to potentially terminate outer loop
            start_color[pos++] = '-';
            break;
        } else {
            // Random other character
            start_color[pos++] = 'A' + (rand() % 26);
        }
    }

    // Ensure null termination
    if (pos >= sizeof(start_color)) {
        pos = sizeof(start_color) - 1;
    }
    start_color[pos] = '\0';

    // Reset p to start for loop
    p = start_color;
}