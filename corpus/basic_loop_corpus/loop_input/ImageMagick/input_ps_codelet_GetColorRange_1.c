#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char start_color[1 << 20] __attribute__((aligned(4096)));
char *p;

void init_vars() {
    // Initialize start_color with a pattern that ensures the loop runs for a predictable amount of time
    // Pattern: repeat blocks of "abc(def)gh-" to trigger nested loops and pointer advancement
    const char pattern[] = "abc(def)gh-";
    const size_t pattern_len = sizeof(pattern) - 1; // exclude null terminator
    size_t data_size = sizeof(start_color);
    
    for (size_t i = 0; i < data_size; ) {
        size_t remaining = data_size - i;
        size_t chunk = (remaining > pattern_len) ? pattern_len : remaining;
        for (size_t j = 0; j < chunk; j++) {
            start_color[i + j] = pattern[j];
        }
        i += chunk;
    }

    // Ensure the last character is null to act as sentinel
    start_color[data_size - 1] = '\x00';

    // Initialize p to point to the beginning of start_color
    p = start_color;
}