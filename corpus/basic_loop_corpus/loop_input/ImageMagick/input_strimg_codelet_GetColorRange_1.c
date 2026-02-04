#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char start_color[4096];
char *p;

void init_vars() {
    // Initialize start_color with data to ensure loop runs for ~0.01 seconds
    // On a typical CPU, 0.01s corresponds to roughly 10-100 million operations.
    // The inner loop skips over content between parentheses, so we can create a pattern that triggers this logic repeatedly.
    // We'll fill the buffer with repeating patterns of "(xxxx)-" to force traversal through many groups.

    const size_t buf_size = sizeof(start_color);
    size_t pos = 0;
    const char pattern[] = "(xxxxxxxxxxxxxxxx)";
    const size_t pattern_len = sizeof(pattern) - 1;

    while (pos < buf_size - 32) {
        // Copy pattern
        for (size_t i = 0; i < pattern_len && pos < buf_size - 1; ++i) {
            start_color[pos++] = pattern[i];
        }
        // Add terminating condition after several iterations
        if (pos + 2 < buf_size) {
            start_color[pos++] = '-';
            start_color[pos++] = '\x00';
        } else {
            break;
        }
    }

    // Ensure null termination within bounds
    if (pos >= buf_size) pos = buf_size - 1;
    start_color[pos] = '\x00';

    // Initialize p to point to start of array
    p = start_color;
}