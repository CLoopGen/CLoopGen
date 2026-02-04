#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char start_color[4096];
char *p;

void init_vars() {
    // Initialize the start_color array with a pattern that ensures the loop runs long enough
    // to take approximately 0.01 seconds, but within the 4KB bound (since array is fixed at 4096 bytes)

    size_t len = 4096;
    for (size_t i = 0; i < len - 1; i++) {
        // Fill with printable characters, occasionally inserting '(' and ')'
        if (i % 256 == 0 && i + 3 < len - 1) {
            start_color[i] = '(';
            start_color[i+1] = 'a';
            start_color[i+2] = ')';
            i += 2;
        } else {
            start_color[i] = 'x'; // filler
        }
    }

    // Ensure termination condition near the end
    start_color[len - 1] = '-';

    // Initialize p to point to start of array
    p = start_color;
}