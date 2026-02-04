#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

char start_color[4096];
char *p;

void init_vars() {
    // Initialize start_color with a pattern that ensures the loop runs long enough
    // but terminates safely. We'll create a large string with nested patterns
    // to simulate realistic traversal, aiming for ~10-20ms runtime.
    
    size_t total_size = sizeof(start_color);
    
    // Fill with repeating patterns containing parentheses and non-dash chars
    for (size_t i = 0; i < total_size - 10; i += 10) {
        // Insert a group like "abc(def)ghi" repeatedly
        start_color[i] = 'a';
        start_color[i+1] = 'b';
        start_color[i+2] = 'c';
        start_color[i+3] = '(';
        start_color[i+4] = 'd';
        start_color[i+5] = 'e';
        start_color[i+6] = 'f';
        start_color[i+7] = ')';
        start_color[i+8] = 'g';
        start_color[i+9] = 'h';
    }
    
    // Place a '-' near the end to ensure termination, but far enough to allow traversal
    start_color[total_size - 1] = '-';
    
    // Ensure p is initialized properly when loop starts
    p = start_color;
}