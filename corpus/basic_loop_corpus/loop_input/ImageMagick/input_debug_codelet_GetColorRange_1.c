#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char start_color[4096];
char *p;

void init_vars() {
    // Initialize start_color with a pattern that ensures realistic traversal
    // Pattern: contains several '(' and ')' pairs, '-' at the end to terminate outer loop
    size_t idx = 0;
    while (idx < sizeof(start_color) - 100) {
        if (rand() % 20 == 0) {
            start_color[idx++] = '(';
            int depth = 1;
            while (depth > 0 && idx < sizeof(start_color) - 50) {
                if (rand() % 15 == 0) {
                    start_color[idx++] = '(';
                    depth++;
                } else if (rand() % 8 == 0) {
                    start_color[idx++] = ')';
                    depth--;
                } else {
                    start_color[idx] = 'a' + (rand() % 26);
                    idx++;
                }
            }
        } else {
            start_color[idx++] = 'a' + (rand() % 26);
        }
    }

    // Add a '-' near the end to ensure the loop terminates naturally
    start_color[sizeof(start_color) - 2] = '-';
    start_color[sizeof(start_color) - 1] = '\x00';

    // Seed p to start of array
    p = start_color;
}