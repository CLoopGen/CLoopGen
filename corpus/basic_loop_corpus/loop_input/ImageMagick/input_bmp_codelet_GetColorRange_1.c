#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char start_color[268435456]; // 256MB buffer
char *p;

void init_vars() {
    // Initialize the buffer with data to ensure meaningful execution time (~0.01s)
    size_t i = 0;
    // Fill with a pattern that includes '(', ')', '-', and '\0' appropriately
    while (i < sizeof(start_color) - 100) {
        if (rand() % 50 == 0) {
            start_color[i++] = '(';
            // Add some content inside parentheses
            while (i < sizeof(start_color) - 10 && rand() % 10 != 0) {
                start_color[i++] = 'a' + (rand() % 26);
            }
            if (i < sizeof(start_color)) {
                start_color[i++] = ')';
            }
        } else if (rand() % 100 == 0) {
            start_color[i++] = '-';
            break; // Ensure loop will terminate on '-'
        } else {
            start_color[i++] = 'a' + (rand() % 26);
        }
    }

    // Guarantee null termination before end
    if (i >= sizeof(start_color)) {
        i = sizeof(start_color) - 1;
    }
    start_color[i] = '\0';

    // Reset p for use in loop
    p = start_color;
}