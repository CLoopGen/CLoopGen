#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

#define DATA_SIZE (64 * 1024 * 1024) // 64 MB for ~0.01 sec runtime

char start_color[DATA_SIZE];
char *p;

void init_vars() {
    // Initialize start_color with a pattern that triggers the loop logic
    size_t pos = 0;
    
    // Fill most of the buffer with normal characters
    while (pos < DATA_SIZE - 1024) {
        if (rand() % 50 == 0) {
            // Insert occasional '(' ... ')' groups
            start_color[pos++] = '(';
            int group_len = rand() % 20 + 1;
            for (int i = 0; i < group_len && pos < DATA_SIZE - 1; i++) {
                start_color[pos++] = 'a' + (rand() % 26);
            }
            if (pos < DATA_SIZE - 1) {
                start_color[pos++] = ')';
            }
        } else if (rand() % 100 == 0) {
            // Occasionally insert '-' to allow early termination
            start_color[pos++] = '-';
        } else {
            // Normal character
            start_color[pos++] = 'a' + (rand() % 26);
        }
    }
    
    // Ensure buffer is null-terminated
    if (pos < DATA_SIZE) {
        start_color[pos] = '\x00';
    } else {
        start_color[DATA_SIZE - 1] = '\x00';
    }
}