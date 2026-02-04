#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char start_color[262144]; // 256KB buffer to ensure ~0.01s runtime
char *p;

void init_vars() {
    // Initialize start_color with data that ensures safe traversal
    // Fill with printable characters, include '(' and ')' pairs, avoid '-' until near end
    size_t i = 0;
    const size_t size = sizeof(start_color) - 32; // Leave room at the end

    // Fill most of the buffer with 'a' and insert some parenthesized sections
    while (i < size - 100) {
        if (i % 100 == 0 && i > 0) {
            start_color[i++] = '(';
            for (int j = 0; j < 10; j++) {
                start_color[i++] = 'x';
            }
            start_color[i++] = ')';
        } else {
            start_color[i++] = 'a';
        }
    }

    // Add a few more parentheses closer to the end
    start_color[i++] = '(';
    for (int j = 0; j < 15; j++) {
        start_color[i++] = 'y';
    }
    start_color[i++] = ')';

    // Fill remainder with 'a'
    while (i < size - 1) {
        start_color[i++] = 'a';
    }

    // Null terminate and ensure loop stops naturally
    start_color[i++] = '-';
    start_color[i] = '\x00';

    // Initialize p to somewhere valid (will be set in loop anyway)
    p = start_color;
}