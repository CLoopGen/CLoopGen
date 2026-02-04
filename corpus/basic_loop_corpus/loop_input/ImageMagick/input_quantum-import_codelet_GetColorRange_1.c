#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char start_color[262144]; // 256KB buffer to ensure ~0.01s runtime
char *p;

void init_vars() {
    // Initialize start_color with data that triggers realistic loop behavior
    size_t size = sizeof(start_color) - 32; // Leave room for null terminator and safety
    size_t i = 0;
    
    while (i < size - 10) {
        // Randomly insert either normal characters or parenthesized groups
        if (rand() % 5 == 0) {
            start_color[i++] = '(';
            // Insert some content inside parentheses
            int inner_len = 1 + rand() % 15;
            for (int j = 0; j < inner_len && i < size - 10; j++) {
                start_color[i++] = 'a' + (rand() % 26);
            }
            start_color[i++] = ')';
        } else {
            start_color[i++] = 'a' + (rand() % 26);
        }
    }
    
    // Ensure we don't exceed buffer and end with either '-' or '\0'
    if (i >= sizeof(start_color)) {
        i = sizeof(start_color) - 1;
    }
    start_color[i] = '\0';
}