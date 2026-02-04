#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char start_color[1 << 20] __attribute__((aligned(4096)));
char *p;

void init_vars() {
    // Initialize start_color with data that ensures the loop runs for a measurable duration
    // Pattern: fill with characters that trigger the inner loop (parentheses) periodically
    size_t size = sizeof(start_color);
    for (size_t i = 0; i < size - 1; i++) {
        if (i % 100 == 0 && i + 10 < size - 1) {
            start_color[i] = '(';
            for (int j = 1; j < 10 && i + j < size - 1; j++) {
                start_color[i + j] = 'a' + (j % 26);
            }
            start_color[i + 10] = ')';
            i += 10;
        } else {
            start_color[i] = 'a' + (i % 25); // printable char, not '-' or '\0'
        }
    }
    // Ensure termination condition near the end if not already set
    start_color[size - 1] = '\0';
}