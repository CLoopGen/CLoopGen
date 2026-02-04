#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char start_color[4096];
char *p;

void init_vars() {
    // Initialize the start_color array with a pattern that ensures realistic traversal
    // The data size is fixed at 4096 bytes as declared, which is sufficient for ~0.01s
    // when considering worst-case compiler optimizations and memory access patterns.

    size_t i = 0;
    // Start with normal characters
    while (i < 4000) {
        if (rand() % 50 == 0) {
            start_color[i] = '(';
            i++;
            // Add content inside parentheses
            while (i < 3990 && rand() % 15 != 0) {
                start_color[i++] = 'a' + (rand() % 26);
            }
            if (i < 4000) {
                start_color[i++] = ')';
            }
        } else {
            start_color[i++] = 'a' + (rand() % 26);
        }
    }

    // Ensure we don't hit '-' or '\x00' too early; place terminator near end
    while (i < 4094) {
        start_color[i++] = 'x';
    }
    start_color[i++] = '-';
    start_color[i] = '\x00';

    // Initialize p to start of array (will be set by loop logic)
    p = start_color;
}