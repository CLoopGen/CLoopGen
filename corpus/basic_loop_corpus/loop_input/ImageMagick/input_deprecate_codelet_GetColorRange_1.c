#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char start_color[268435456]; // 256MB buffer
char *p;

void init_vars() {
    // Initialize the large buffer with a pattern that ensures realistic traversal
    size_t size = sizeof(start_color);
    size_t i = 0;

    while (i < size - 100) {
        // Randomly insert either normal characters or parenthesized blocks
        if (rand() % 5 == 0) {
            start_color[i++] = '(';
            // Fill inside parentheses with random content
            while (i < size - 10 && start_color[i-1] != ')') {
                start_color[i++] = 'a' + (rand() % 26);
            }
            if (i < size) {
                start_color[i++] = ')';
            }
        } else {
            // Normal character, avoid '-' and '\0' until near the end
            start_color[i++] = 'a' + (rand() % 26);
        }
    }

    // Ensure we eventually hit a terminator within bounds
    while (i < size - 1) {
        start_color[i++] = 'x'; // filler
    }
    start_color[size - 1] = '\0'; // guaranteed termination

    // Initialize p to start of array
    p = start_color;
}