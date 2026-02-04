#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char start_color[4096];
char *p;

void init_vars() {
    // Initialize start_color with data to ensure loop runs for desired time
    // The loop processes characters until it finds '-' or '\0', skipping content inside parentheses.
    // We need to create a large enough input so that the loop runs ~0.01 seconds.
    // Since the array is only 4096 bytes, we fill it completely.

    size_t total_size = sizeof(start_color);
    char *data = start_color;

    // We'll construct a pattern that causes significant execution:
    // Multiple "(...)" groups with non-matching ')' and some '(' without ')'
    // But must not cause out-of-bounds access.

    size_t pos = 0;
    const char pattern1[] = "(";   // start of group
    const char pattern2[] = ")";   // end of group
    const char filler = 'a';

    while (pos < total_size - 32) {
        if (pos + 4 < total_size) {
            data[pos++] = '(';
            // Fill inner content until next available spot for closing
            size_t inner_len = (total_size - pos - 10) / 100; // small inner length to have many groups
            if (inner_len == 0) inner_len = 1;
            if (pos + inner_len + 1 >= total_size) break;
            memset(data + pos, 'x', inner_len);
            pos += inner_len;
            data[pos++] = ')';
        } else {
            break;
        }
    }

    // Fill remaining space with filler
    while (pos < total_size - 1) {
        data[pos++] = filler;
    }
    // Ensure last character is not '\0' or '-', so loop runs through entire buffer
    // But we must guarantee termination condition eventually met
    // So place a '-' at the very end to terminate the outer loop safely
    data[total_size - 1] = '-';

    // Initialize p to start of array (will be overwritten in loop, but safe)
    p = start_color;
}