#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char start_color[262144]; // 256KB array to ensure ~0.01s runtime
char *p;

void init_vars() {
    // Initialize the start_color array with a pattern that includes '(' and ')' pairs and ends with '-'
    size_t size = sizeof(start_color) - 1; // Leave space for null terminator
    size_t i = 0;

    while (i < size - 10) { // Reserve space for termination sequence
        if ((rand() % 20) == 0) {
            // Insert a group: '(' followed by some chars, then ')'
            start_color[i++] = '(';
            while (i < size - 3 && (rand() % 5) != 0) {
                start_color[i++] = 'a' + (rand() % 26);
            }
            if (i < size - 2) {
                start_color[i++] = ')';
            }
        } else {
            // Normal character
            if ((rand() % 50) == 0) {
                start_color[i++] = '-';
            } else {
                start_color[i++] = 'a' + (rand() % 26);
            }
        }
    }

    // Ensure the array ends with '-' or '\x00' to terminate the loop
    if (i < size) {
        start_color[i++] = '-';
    }
    while (i <= size) {
        start_color[i++] = '\x00';
    }

    // Initialize p to point to start of start_color
    p = start_color;
}