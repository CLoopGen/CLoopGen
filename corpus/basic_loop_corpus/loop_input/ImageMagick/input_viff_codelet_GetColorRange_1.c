#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char start_color[4096];
char *p;

void init_vars() {
    // Initialize the start_color array with a pattern that will cause the loop to traverse most of it
    // but still terminate properly. We'll create a sequence with nested parentheses and end with '-'
    int size = sizeof(start_color);
    
    // Fill with '(' followed by non-matching ')' to force deep scanning
    for (int i = 0; i < size - 256; i++) {
        start_color[i] = 'a' + (i % 26);
        // Occasionally insert a parenthetical group
        if (i % 100 == 0 && i + 50 < size - 256) {
            start_color[i] = '(';
            for (int j = 1; j < 40; j++) {
                start_color[i + j] = 'x';
            }
            start_color[i + 40] = ')';
            i += 40;
        }
    }
    
    // Add a long stretch of non-terminating characters
    for (int i = size - 256; i < size - 2; i++) {
        start_color[i] = 'X';
    }
    
    // Make sure last few bytes don't cause overflow: end with '-' to terminate loop cleanly
    start_color[size - 2] = 'X';
    start_color[size - 1] = '-';
}