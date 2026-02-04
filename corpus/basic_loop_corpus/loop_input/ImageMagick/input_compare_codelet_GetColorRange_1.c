#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char start_color[4096];
char *p;

void init_vars() {
    // Initialize start_color with a pattern that ensures realistic traversal
    // Fill with nested parentheses and '-' at the end to control termination
    size_t pos = 0;
    
    // Create a large pattern with multiple ( ... ) groups
    while (pos < sizeof(start_color) - 100) {
        if (pos + 20 < sizeof(start_color)) {
            start_color[pos++] = '(';
            for (int j = 0; j < 15 && pos < sizeof(start_color); j++) {
                start_color[pos++] = 'a' + (j % 26);
            }
            if (pos < sizeof(start_color)) {
                start_color[pos++] = ')';
            }
        } else {
            break;
        }
    }
    
    // Add some non-parentheses content
    while (pos < sizeof(start_color) - 10) {
        start_color[pos++] = 'x';
    }
    
    // Ensure loop terminates on '-' near the end
    start_color[pos++] = '-';
    while (pos < sizeof(start_color)) {
        start_color[pos++] = 'y';
    }
    
    // Explicitly null terminate just in case
    start_color[sizeof(start_color)-1] = '\0';
    
    // Initialize p to point to start of array
    p = start_color;
}