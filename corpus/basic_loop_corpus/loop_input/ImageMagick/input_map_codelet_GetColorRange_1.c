#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char start_color[4096];
char *p;

void init_vars() {
    // Initialize start_color with a pattern that will make the loop run for significant time
    // We'll create a large nested structure with parentheses and non-matching characters
    // to ensure deep traversal without early termination
    
    size_t total_size = sizeof(start_color);
    
    // Fill with mostly '(' and '-' separated by many characters
    for (size_t i = 0; i < total_size - 100; i++) {
        if (i % 128 == 0 && i + 50 < total_size) {
            start_color[i] = '(';
            // Add closing ')' far ahead to force long inner loop
            start_color[i + 50] = ')';
        } else if ((i % 7) == 0 && i > 0 && start_color[i-1] != '(' && start_color[i-1] != ')') {
            start_color[i] = '-';
        } else {
            start_color[i] = 'a' + (i % 26);
        }
    }
    
    // Ensure null termination near the end, but not exactly at end to allow loop to break naturally
    start_color[total_size - 1] = '\x00';
    
    // Make sure last few positions don't have premature terminators
    for (int i = 0; i < 10; i++) {
        if (start_color[total_size - 1 - i] == '-') {
            start_color[total_size - 1 - i] = 'z';
        }
    }
    
    // Reset p to start of array
    p = start_color;
}