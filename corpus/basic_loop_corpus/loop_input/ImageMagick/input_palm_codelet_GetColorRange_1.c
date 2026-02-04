#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char start_color[4096];
char *p;

void init_vars() {
    // Initialize start_color with a pattern that will make the loop run for significant time
    // We'll create a large string with nested structure to ensure deep traversal
    size_t total_size = 4096;
    
    // Fill with repeating patterns containing parentheses and non-delimiter chars
    for (size_t i = 0; i < total_size - 100; i += 100) {
        // Insert several parenthesized groups
        start_color[i] = 'a';
        start_color[i+1] = '(';
        start_color[i+2] = 'b';
        start_color[i+3] = 'c';
        start_color[i+4] = 'd';
        start_color[i+5] = ')';
        start_color[i+6] = 'e';
        start_color[i+7] = '(';
        start_color[i+8] = 'f';
        start_color[i+9] = 'g';
        start_color[i+10] = 'h';
        start_color[i+11] = ')';
        start_color[i+12] = 'i';
        // Add some dashes periodically but not too early
        if ((i % 256) == 0 && i > 0) {
            start_color[i+13] = '-';
            // Ensure rest of buffer is zeroed after this point
            memset(start_color + i + 14, 0, total_size - (i + 14));
            break;
        } else {
            start_color[i+13] = 'j';
        }
    }
    
    // Make sure last byte is null terminator
    start_color[total_size - 1] = '\0';
    
    // Ensure there's no premature termination
    for (int i = 0; i < 10; i++) {
        if (start_color[i] == '-' || start_color[i] == '\0') {
            start_color[i] = 'x';
        }
    }
    
    // Force the terminating condition near the end
    int term_pos = 3900;
    start_color[term_pos] = '-';
    for (int i = term_pos + 1; i < 4096; i++) {
        start_color[i] = '\0';
    }
}