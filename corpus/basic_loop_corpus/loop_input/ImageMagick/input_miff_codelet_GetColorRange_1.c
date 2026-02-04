#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char start_color[4096];
char *p;

void init_vars() {
    // Initialize the start_color array with a pattern that will cause the loop to run for a significant time
    // We'll create a large block of data with nested parentheses and dashes at the end
    // This ensures we don't go out of bounds and control the execution time
    
    const size_t data_size = 2 * 1024 * 1024; // ~2MB total logical data, repeated in 4KB buffer
    size_t idx = 0;
    
    // Fill the buffer repeatedly with patterns until we cover effective data size
    while (idx < sizeof(start_color)) {
        // Create a sequence with open paren, some chars, close paren, repeat
        if ((idx + 10) < sizeof(start_color)) {
            start_color[idx++] = '(';
            for (int j = 0; j < 5 && idx < sizeof(start_color); j++) {
                start_color[idx++] = 'a' + (idx % 26);
            }
            if (idx < sizeof(start_color)) {
                start_color[idx++] = ')';
            }
        } else {
            // Near the end, place a dash to terminate the outer loop
            start_color[idx++] = '-';
        }
    }
    
    // Ensure null termination
    if (sizeof(start_color) > 0) {
        start_color[sizeof(start_color)-1] = '\0';
    }
    
    // Reset p to point to start of start_color
    p = start_color;
}