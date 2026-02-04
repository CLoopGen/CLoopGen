#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE (64 * 1024 * 1024)

char start_color[DATA_SIZE];
char *p;

void init_vars() {
    // Initialize the buffer with a pattern that includes parentheses and hyphens
    size_t pos = 0;
    
    while (pos < DATA_SIZE - 100) {
        // Randomly decide to insert a group or plain text
        if (rand() % 5 == 0) {
            start_color[pos++] = '(';
            // Fill inside parentheses
            int inner_len = rand() % 15 + 1;
            for (int i = 0; i < inner_len && pos < DATA_SIZE - 2; i++) {
                start_color[pos++] = 'a' + (rand() % 26);
            }
            if (pos < DATA_SIZE - 1) {
                start_color[pos++] = ')';
            }
        } else {
            // Add normal characters
            if (rand() % 20 == 0) {
                // Insert '-' to potentially terminate early
                start_color[pos++] = '-';
            } else if (rand() % 100 == 0) {
                // Occasionally insert null terminator
                start_color[pos++] = '\x00';
            } else {
                start_color[pos++] = 'a' + (rand() % 26);
            }
        }
    }
    
    // Ensure last few bytes are safe
    while (pos < DATA_SIZE - 1) {
        start_color[pos++] = 'x';
    }
    start_color[DATA_SIZE - 1] = '\x00';  // Guarantee null termination at end
    
    // Reset p to start for loop
    p = start_color;
}