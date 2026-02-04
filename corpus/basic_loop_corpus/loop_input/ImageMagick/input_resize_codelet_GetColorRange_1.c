#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char start_color[4096];
char *p;

void init_vars() {
    // Initialize start_color with data to ensure loop runs for ~0.01 seconds
    // Approximate required data size: aim for several million iterations
    // Pattern: fill with non-'-', non-null, include '(' and ')' pairs

    const size_t size = 4096;
    for (size_t i = 0; i < size - 32; i++) {
        if (i % 50 == 0 && i + 10 < size - 32) {
            start_color[i] = '(';
            for (int j = 1; j < 8; j++) {
                start_color[i + j] = 'a' + (j % 26);
            }
            start_color[i + 8] = ')';
            i += 8;
        } else {
            start_color[i] = 'x';
        }
    }

    // Ensure termination with '-' at the end to prevent overflow
    start_color[size - 1] = '-';
}