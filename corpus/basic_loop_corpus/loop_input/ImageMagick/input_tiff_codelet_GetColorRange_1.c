#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char start_color[4096];
char *p;

void init_vars() {
    // Initialize start_color with data to ensure loop runs ~0.01s
    // Approximate 1MB of effective input: repeat pattern across blocks
    const size_t total_size = 1 << 20; // 1MB
    const size_t pattern_len = sizeof(start_color);
    char *data = (char*)malloc(total_size);
    
    // Create a pattern that includes '(' and ')' pairs and ends with '-'
    for (size_t i = 0; i < pattern_len - 64; i++) {
        if (i % 64 == 0) {
            data[i] = '(';
            for (int j = 1; j < 62; j++) data[i + j] = 'a' + (j % 26);
            data[i + 62] = ')';
            data[i + 63] = ' ';
            i += 63;
        } else {
            data[i] = 'x';
        }
    }
    // Fill remainder with 'x', then end with '-' at total_size-1
    for (size_t i = pattern_len - 64; i < total_size - 1; i++) {
        data[i] = 'x';
    }
    data[total_size - 1] = '-';

    // Copy repeated chunks into start_color circularly
    for (size_t i = 0; i < sizeof(start_color); i++) {
        start_color[i] = data[i % total_size];
    }

    // Ensure start_color ends with '-' if we hit the boundary
    if (sizeof(start_color) > 0) {
        start_color[sizeof(start_color)-1] = '-';
    }

    // Initialize p to start of start_color
    p = start_color;

    free(data);
}