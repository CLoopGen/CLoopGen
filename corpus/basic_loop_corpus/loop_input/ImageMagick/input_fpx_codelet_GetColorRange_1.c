#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char start_color[262144]; // 256KB buffer to ensure ~0.01s runtime
char *p;

void init_vars() {
    // Initialize start_color with a pattern that includes parentheses and ends with '-'
    size_t size = sizeof(start_color) - 1; // Leave space for null terminator
    size_t i = 0;
    
    // Fill most of the buffer with normal characters
    while (i < size - 100) {
        if (rand() % 50 == 0) {
            // Insert a group like "(...)" every now and then
            start_color[i++] = '(';
            int inner_len = rand() % 8 + 1;
            for (int j = 0; j < inner_len && i < size - 100; j++) {
                start_color[i++] = 'a' + (rand() % 26);
            }
            if (i < size - 100)
                start_color[i++] = ')';
        } else {
            start_color[i++] = 'a' + (rand() % 26);
        }
    }
    
    // Add some more content, then terminate with '-' at near the end
    while (i < size - 2) {
        start_color[i++] = 'x';
    }
    start_color[i++] = '-';
    start_color[i] = '\0';
}