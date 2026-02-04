#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char start_color[268435456]; // 256MB buffer
char *p;

void init_vars() {
    // Initialize the buffer with data to ensure meaningful execution
    size_t len = sizeof(start_color);
    for (size_t i = 0; i < len - 1; i++) {
        // Randomly place '(', ')', '-', or other characters, avoiding '\x00' until near end
        int r = rand() % 50;
        if (r == 0) {
            start_color[i] = '(';
        } else if (r == 1) {
            start_color[i] = ')';
        } else if (r == 2) {
            start_color[i] = '-';
        } else {
            start_color[i] = 'a' + (rand() % 26);
        }
    }
    // Ensure null terminator at the end to prevent out-of-bounds
    start_color[len - 1] = '\x00';

    // Reset p to point to start of buffer in case it's used before loop
    p = start_color;
}