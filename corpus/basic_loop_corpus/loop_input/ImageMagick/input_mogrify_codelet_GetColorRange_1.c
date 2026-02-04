#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char start_color[4096];
char *p;

void init_vars() {
    // Initialize start_color with a pattern that ensures the loop runs for a significant time
    // We'll create a large string with nested parentheses and separators to control traversal
    
    size_t size = sizeof(start_color);
    for (size_t i = 0; i < size - 32; i++) {
        if (i % 128 == 0) {
            // Insert '(' followed by non-terminating chars, then ')'
            start_color[i] = '(';
            size_t j;
            for (j = 1; j < 64 && (i + j + 1) < size - 1; j++) {
                start_color[i + j] = 'a' + (j % 26);
            }
            start_color[i + j] = ')';
            i += j;
        } else if (i % 32 == 0) {
            // Occasionally insert '-' to prevent premature termination
            start_color[i] = 'x';
        } else {
            start_color[i] = 'x';
        }
    }

    // Ensure null termination near the end but not exactly at size-1 to allow safe scanning
    start_color[size - 1] = '\0';

    // Set initial p to start of array
    p = start_color;
}