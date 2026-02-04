#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char start_color[1 << 20]; // 1MB buffer
char *p;

void init_vars() {
    // Initialize start_color with a pattern that ensures realistic traversal:
    // Mix of normal characters, '(', ')', '-', and '\0' to trigger the loop logic
    size_t i = 0;
    while (i < sizeof(start_color) - 32) {
        // Randomly decide to insert a parenthesized block or normal text
        if (rand() % 8 == 0) {
            start_color[i++] = '(';
            // Fill inside until closing ')'
            while (i < sizeof(start_color) - 32 && rand() % 16 != 0)
                start_color[i++] = 'a' + (rand() % 26);
            start_color[i++] = ')';
        } else if (rand() % 128 == 0) {
            start_color[i++] = '-';
            break;
        } else {
            start_color[i++] = 'a' + (rand() % 26);
        }
    }

    // Ensure null termination if loop didn't end early
    if (i < sizeof(start_color))
        start_color[i] = '\0';
}