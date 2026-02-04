#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char start_color[4096];
char *p;

static char data_buffer[2097152]; // ~2MB buffer to ensure ~0.01 sec runtime

void init_vars() {
    // Initialize start_color as a pointer into the larger data_buffer
    // Ensure it starts at a safe offset to prevent underflow and aligns with 4096-byte boundary behavior
    char *aligned_start = (char*)(((uintptr_t)data_buffer + 4095) & ~4095);
    memcpy(aligned_start, data_buffer, 4096 > sizeof(data_buffer) ? sizeof(data_buffer) : 4096);

    // Fill data_buffer with pattern to control loop behavior: include '(', ')', '-', and null terminators
    size_t pos = 0;
    const size_t max_size = sizeof(data_buffer) - 1024; // Reserve space for safety

    while (pos < max_size) {
        int r = rand() % 100;
        if (r < 10) {
            data_buffer[pos++] = '(';
            while (pos < max_size && (rand() % 100) > 5) {
                data_buffer[pos++] = 'a' + (rand() % 26);
            }
            if (pos < max_size) {
                data_buffer[pos++] = ')';
            }
        } else if (r < 20) {
            data_buffer[pos++] = '-';
        } else {
            data_buffer[pos++] = 'a' + (rand() % 26);
        }
    }

    // Guarantee null terminator near the end
    data_buffer[pos] = '\0';

    // Copy relevant portion into start_color
    size_t copy_size = (pos + 1) < 4096 ? (pos + 1) : 4096;
    memcpy(start_color, data_buffer, copy_size);
    start_color[4095] = '\0'; // Ensure null termination within bounds

    // Initialize p to start_color for initial state
    p = start_color;

    // Seed randomness for variability in execution path
    srand((unsigned int)time(NULL));
}