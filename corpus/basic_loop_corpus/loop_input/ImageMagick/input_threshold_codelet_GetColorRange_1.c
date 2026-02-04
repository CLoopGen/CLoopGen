#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char start_color[268435456]; // 256 MB buffer
char *p;

void init_vars() {
    // Initialize p to NULL to avoid undefined behavior before loop sets it
    p = NULL;

    // Fill start_color with data to ensure the loop runs for ~0.01 seconds
    // We aim for a mix of characters to simulate realistic traversal including parentheses and hyphens
    size_t total_size = sizeof(start_color);
    size_t i = 0;

    while (i < total_size - 32) { // Leave room at end
        if ((rand() % 100) < 10) {
            // Insert a group: '(' followed by non-) chars, then ')'
            start_color[i++] = '(';
            while (i < total_size - 1 && (rand() % 100) > 15) {
                start_color[i++] = 'a' + (rand() % 26);
            }
            if (i < total_size - 1) {
                start_color[i++] = ')';
            }
        } else {
            // Normal character: mostly letters, occasionally '-' to terminate early sometimes
            if ((rand() % 100) < 5 && i > total_size / 2) {
                start_color[i++] = '-';
            } else {
                start_color[i++] = 'a' + (rand() % 26);
            }
        }
    }

    // Ensure null termination near the end to allow loop exit via '\x00'
    start_color[total_size - 1] = '\x00';

    // Seed p to start of array when loop begins (but leave p=NULL now; loop assigns it)
}