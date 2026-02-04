#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char start_color[1 << 20] __attribute__((aligned(4096)));
char *p;

void init_vars() {
    // Initialize start_color with a pattern that ensures realistic traversal
    // Mix of '(', ')', '-', and other characters to trigger the loop logic
    size_t size = sizeof(start_color);
    for (size_t i = 0; i < size - 1; i++) {
        if (i % 128 == 0 && i + 3 < size) {
            start_color[i] = '(';
            start_color[i+1] = 'x';
            start_color[i+2] = ')';
            i += 2;
        } else {
            // Mostly normal text, occasionally insert '-' at end
            start_color[i] = (rand() % 50 == 0) ? '-' : 'a' + (i % 26);
        }
    }
    // Ensure last character is '\0' to act as terminator
    start_color[size - 1] = '\0';

    // Initialize p to point to start of start_color
    p = start_color;
}