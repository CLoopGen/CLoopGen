#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char start_color[268435456]; // 256 MB array to ensure ~0.01 sec runtime
char *p;

void init_vars() {
    // Initialize the array with data that ensures valid traversal
    size_t i = 0;
    // Fill most of the array with regular characters
    for (; i < sizeof(start_color) - 1024; i++) {
        start_color[i] = 'a' + (i % 26);
    }

    // Insert a '(' followed by non ')' chars, then a ')'
    start_color[i++] = '(';
    for (int j = 0; j < 100 && i < sizeof(start_color) - 1; j++, i++) {
        start_color[i] = 'x';
    }
    if (i < sizeof(start_color)) {
        start_color[i++] = ')';
    }

    // Continue filling until near the end
    for (; i < sizeof(start_color) - 2; i++) {
        start_color[i] = 'a' + (i % 26);
    }

    // Place '-' at second to last position to terminate outer loop
    start_color[i++] = '-';
    // Ensure null termination
    start_color[i] = '\x00';

    // Initialize pointer p to start of array (will be updated in loop)
    p = start_color;
}