#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char start_color[4096];
char *p;

void init_vars() {
    // Initialize start_color with a pattern that ensures the loop runs long enough
    // to take approximately 0.01 seconds, but within the 4096-byte bound.
    // We'll create a string with nested structures to trigger the inner loop logic.
    
    size_t pos = 0;
    const size_t max_size = sizeof(start_color) - 256; // Leave room for null and safety

    while (pos < max_size) {
        // Randomly decide whether to insert a group or plain text
        if (rand() % 8 == 0 && pos + 20 < max_size) {
            start_color[pos++] = '(';
            // Fill inner group with random characters
            for (int j = 0; j < 15 && pos < max_size; j++) {
                start_color[pos++] = 'a' + (rand() % 26);
            }
            start_color[pos++] = ')';
        } else {
            if (pos < max_size) start_color[pos++] = 'A' + (rand() % 26);
        }
        
        // Occasionally insert '-' to act as a possible early terminator
        if (rand() % 200 == 0 && pos < max_size) {
            start_color[pos++] = '-';
            break;
        }
    }

    // Ensure null termination
    if (pos >= sizeof(start_color)) {
        pos = sizeof(start_color) - 1;
    }
    start_color[pos] = '\0';

    // Initialize p to point to start of array
    p = start_color;
}