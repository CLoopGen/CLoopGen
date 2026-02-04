#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char start_color[4096];
char *p;

static char large_buffer[1 << 20]; // 1MB buffer for data

void init_vars() {
    // Initialize start_color as a pointer to the beginning of our large buffer
    memcpy(start_color, large_buffer, sizeof(start_color));

    // Fill the large buffer with patterned data to control loop behavior
    size_t total_size = sizeof(large_buffer);
    size_t i = 0;

    while (i < total_size - 10) {
        // Randomly insert either normal characters or parenthesized groups
        if (rand() % 5 == 0) {
            large_buffer[i++] = '(';
            // Add some content inside parentheses
            int inner_len = rand() % 16 + 1;
            for (int j = 0; j < inner_len && i < total_size - 2; j++) {
                large_buffer[i++] = 'a' + (rand() % 26);
            }
            large_buffer[i++] = ')';
        } else {
            large_buffer[i++] = 'a' + (rand() % 26);
        }
    }

    // Ensure null termination near the end, but not exactly at the end to allow loop to break naturally
    large_buffer[total_size - 1] = '\0';

    // Make sure start_color is initialized from large_buffer
    memcpy(start_color, large_buffer, sizeof(start_color));

    // Seed random generator for predictable test runs
    srand((unsigned int)(time(NULL) ^ (uintptr_t)&p));
}