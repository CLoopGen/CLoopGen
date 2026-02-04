#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

#define DATA_SIZE (128 * 1024 * 1024)

char start_color[DATA_SIZE];
char *p;

void init_vars() {
    // Initialize the data with a pattern that includes parentheses and ends with null terminator
    size_t pos = 0;
    
    // Fill most of the buffer with normal characters and some '('...')' groups
    while (pos < DATA_SIZE - 1024) {
        if (rand() % 50 == 0) {
            start_color[pos++] = '(';
            int group_len = rand() % 64;
            for (int i = 0; i < group_len && pos < DATA_SIZE - 1; i++) {
                start_color[pos++] = 'a' + (rand() % 26);
            }
            if (pos < DATA_SIZE - 1) {
                start_color[pos++] = ')';
            }
        } else {
            start_color[pos++] = 'a' + (rand() % 26);
        }
    }
    
    // Add '-' near the end to ensure loop terminates before hitting null
    // This prevents undefined behavior and ensures termination condition is met
    if (pos < DATA_SIZE - 1) {
        start_color[pos++] = '-';
    }
    
    // Ensure the rest is zeroed and null terminated
    while (pos < DATA_SIZE) {
        start_color[pos++] = '\0';
    }
    
    // Initialize p to start of array
    p = start_color;
}