#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char start_color[268435456]; // 256 MB
char *p;

void init_vars() {
    // Initialize the array with a pattern that includes '(', ')', '-', and other characters
    size_t size = sizeof(start_color);
    size_t i = 0;

    while (i < size - 1024) {
        start_color[i++] = 'a'; // Regular character
        if (i >= size - 1024) break;
        start_color[i++] = '(';
        int nested_length = rand() % 100 + 1; // Random length inside parentheses
        for (int j = 0; j < nested_length && i < size - 1; ++j) {
            start_color[i++] = 'x';
        }
        if (i < size) start_color[i++] = ')';
    }

    // Place '-' near the end to stop the outer loop eventually
    if (i < size) {
        start_color[i++] = '-';
    }
    // Ensure null termination at the end
    for (; i < size; ++i) {
        start_color[i] = '\x00';
    }

    // Initialize p to point to start of array (will be overwritten by loop, but safe initial state)
    p = start_color;
}