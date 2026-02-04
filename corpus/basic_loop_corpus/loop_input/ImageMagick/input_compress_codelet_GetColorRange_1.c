#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char start_color[1 << 20]; // 1MB data
char *p;

void init_vars() {
    // Initialize start_color with a pattern that ensures proper traversal
    // Pattern: repeat of "abc(defg)hij-" to trigger the loop logic
    const char *pattern = "abc(defg)hij";
    const size_t pattern_len = 11;
    const size_t data_size = sizeof(start_color) - 1; // Leave space for null terminator

    for (size_t i = 0; i < data_size;) {
        size_t remaining = data_size - i;
        size_t copy_len = (remaining > pattern_len) ? pattern_len : remaining;
        for (size_t j = 0; j < copy_len; j++) {
            start_color[i + j] = pattern[j];
        }
        i += copy_len;
    }

    // Ensure last character is null to terminate the loop
    start_color[data_size] = '\x00';

    // Initialize p to start of array (will be updated in loop)
    p = start_color;
}