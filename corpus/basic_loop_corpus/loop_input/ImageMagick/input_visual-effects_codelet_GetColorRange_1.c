#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char start_color[4096];
char *p;

void init_vars() {
    // Initialize the start_color array with a pattern that will cause realistic traversal
    // Mix of normal characters, parentheses, and hyphens to simulate color string parsing
    size_t total_size = 1 << 20; // ~1MB data to achieve ~0.01 sec runtime on modern CPU
    static char large_data[1 << 20]; // 1MB static buffer to back our simulated extended memory

    // We'll treat start_color as the beginning of a larger logical buffer
    // First, fill the actual start_color (4KB) with meaningful content
    size_t pos = 0;
    
    while (pos < sizeof(start_color) - 50) {
        // Randomly choose between plain text, parenthesized group, or end marker
        int r = rand() % 20;
        if (r == 0 && pos > 1000) { // Rarely insert '-' after some data
            start_color[pos++] = '-';
            break;
        } else if (r < 3) {
            // Insert a parenthesized group: "(...)"
            start_color[pos++] = '(';
            int len = rand() % 15 + 1;
            for (int i = 0; i < len; i++) {
                if (pos >= sizeof(start_color) - 50) break;
                start_color[pos++] = 'a' + (rand() % 26);
            }
            start_color[pos++] = ')';
        } else {
            // Normal text
            int len = rand() % 8 + 1;
            for (int i = 0; i < len; i++) {
                if (pos >= sizeof(start_color) - 50) break;
                start_color[pos++] = 'a' + (rand() % 26);
            }
        }
    }

    // Ensure null termination if we filled up
    if (pos < sizeof(start_color)) {
        start_color[pos] = '\x00';
    } else {
        start_color[sizeof(start_color)-1] = '\x00';
    }

    // Seed random for consistent behavior
    srand(time(NULL) ^ 0x12345678);

    // Copy start_color into larger buffer and extend it to 1MB if needed
    memcpy(large_data, start_color, sizeof(start_color));
    for (size_t i = sizeof(start_color); i < total_size; i++) {
        large_data[i] = 'a' + (rand() % 26);
    }
    // Place a terminator near the end to prevent out-of-bounds
    large_data[total_size - 1] = '\x00';

    // Make sure p starts at start_color
    p = start_color;
}