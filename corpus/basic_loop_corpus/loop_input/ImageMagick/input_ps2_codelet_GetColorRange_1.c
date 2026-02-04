#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

char start_color[4096];
char *p;

void init_vars() {
    // Initialize start_color with a pattern that ensures realistic execution behavior
    // We'll create a buffer with nested parentheses and '-' terminator at the end
    size_t idx = 0;
    
    // Fill most of the buffer with characters that are not '(', ')', '-', or '\0'
    while (idx < sizeof(start_color) - 64) {
        if (idx + 20 < sizeof(start_color) - 64 && rand() % 8 == 0) {
            // Occasionally insert a parenthesized group: "(...)"
            start_color[idx++] = '(';
            for (int j = 0; j < 15 && idx < sizeof(start_color) - 64; j++) {
                start_color[idx++] = 'a' + (rand() % 26);
            }
            start_color[idx++] = ')';
        } else {
            start_color[idx++] = 'a' + (rand() % 26);
        }
    }
    
    // Add a few more parentheses near the end
    if (idx + 10 < sizeof(start_color) - 1) {
        start_color[idx++] = '(';
        for (int j = 0; j < 5; j++) {
            start_color[idx++] = 'x';
        }
        start_color[idx++] = ')';
    }

    // Ensure we don't hit '\0' before '-', so put '-' near the very end
    if (idx < sizeof(start_color) - 1) {
        start_color[idx++] = 'g'; // filler
    }
    if (idx < sizeof(start_color) - 1) {
        start_color[idx++] = 'h';
    }
    if (idx < sizeof(start_color) - 1) {
        start_color[idx++] = '-';
    }
    
    // Null terminate just after '-'
    while (idx < sizeof(start_color)) {
        start_color[idx++] = '\0';
    }

    // Initialize p to start of array (will be updated in loop)
    p = start_color;
}