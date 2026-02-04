#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char start_color[262144]; // 256KB buffer to ensure ~0.01s runtime
char *p;

void init_vars() {
    // Initialize the buffer with a pattern that includes parentheses and stops at '-'
    size_t i = 0;
    // Fill most of the buffer with normal characters
    for (; i < sizeof(start_color) - 1; i++) {
        if (i % 100 == 0 && i > 0) {
            // Insert a group like "(...)" every 100 characters
            start_color[i] = '(';
            i++;
            if (i >= sizeof(start_color) - 1) break;
            while (i < sizeof(start_color) - 1 && (i % 100) != 98) {
                start_color[i] = 'a';
                i++;
            }
            if (i < sizeof(start_color) - 1) {
                start_color[i] = ')';
            } else {
                break;
            }
        } else {
            // Regular text
            start_color[i] = 'x';
        }
    }
    // Ensure termination condition: no '-' or '\0' until the end
    if (i < sizeof(start_color)) {
        start_color[i] = '\0';
    }
}