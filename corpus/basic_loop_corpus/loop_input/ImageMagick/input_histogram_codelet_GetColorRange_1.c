#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char start_color[1 << 20] __attribute__((aligned(4096)));
char *p;

void init_vars() {
    // Initialize start_color with a pattern that ensures the loop runs for a measurable duration
    // Pattern: Repeat blocks of characters containing '(' ... ')' pairs and non '-' characters, ending with a '-'
    size_t idx = 0;
    const size_t max_size = sizeof(start_color) - 32; // Leave room for null and alignment

    while (idx < max_size) {
        // Add a sequence that triggers the inner loop: '(' followed by non-')' chars, then ')'
        start_color[idx++] = '(';
        for (int j = 0; j < 7 && idx < max_size; j++) {
            start_color[idx++] = 'a' + (j % 26);
        }
        if (idx < max_size) start_color[idx++] = ')';
        // Add some non '-' and non '(' characters
        for (int j = 0; j < 3 && idx < max_size; j++) {
            start_color[idx++] = 'X';
        }
    }

    // Ensure termination condition: set a '-' at the end to stop the outer loop
    start_color[idx++] = '-';
    // Null terminate in case it's reached first
    if (idx < sizeof(start_color)) {
        start_color[idx] = '\x00';
    } else {
        start_color[sizeof(start_color) - 1] = '\x00';
    }

    // Initialize pointer p to start of array
    p = start_color;
}