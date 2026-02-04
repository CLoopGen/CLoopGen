#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char start_color[262144]; // 256KB buffer to ensure ~0.01s runtime
char *p;

void init_vars() {
    // Initialize the start_color array with a pattern that includes parentheses and ends with '-'
    size_t size = sizeof(start_color);
    size_t i = 0;
    
    // Fill most of the buffer with regular characters
    while (i < size - 64) {
        if (rand() % 100 < 10) { // 10% chance to insert a group
            start_color[i++] = '(';
            // Add some content inside parentheses
            int inner_len = 1 + rand() % 15;
            for (int j = 0; j < inner_len && i < size - 64; j++, i++) {
                start_color[i] = 'a' + (rand() % 26);
            }
            if (i < size - 64) {
                start_color[i++] = ')';
            }
        } else {
            start_color[i++] = 'a' + (rand() % 26);
        }
    }
    
    // Ensure we don't exceed bounds
    // Last few bytes: make sure to end with '-' to terminate outer loop
    if (i < size) {
        start_color[i++] = '-';
    }
    // Pad remaining with nulls if needed
    while (i < size) {
        start_color[i++] = '\x00';
    }
}