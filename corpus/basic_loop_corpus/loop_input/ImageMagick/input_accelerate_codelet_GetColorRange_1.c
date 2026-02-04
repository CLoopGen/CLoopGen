#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char start_color[4096];
char *p;

void init_vars() {
    // Initialize start_color with a pattern that ensures the loop runs for a significant time
    // but without exceeding the 4096-byte buffer. We'll create a pattern with nested parentheses
    // and ensure it ends with '-' or '\0' to terminate the outer loop.

    size_t idx = 0;
    // Fill most of the buffer with characters that are not '-', '(', ')', or '\0'
    while (idx < sizeof(start_color) - 64) {
        start_color[idx++] = 'a';
    }

    // Add several "(...)" blocks to trigger inner loop
    for (int i = 0; i < 10 && idx < sizeof(start_color) - 3; ++i) {
        start_color[idx++] = '(';
        for (int j = 0; j < 20 && idx < sizeof(start_color) - 2; ++j) {
            start_color[idx++] = 'x';
        }
        start_color[idx++] = ')';
    }

    // Add one more '(' that will lead to early termination via '\0'
    if (idx < sizeof(start_color) - 1) {
        start_color[idx++] = '(';
    }
    // Now fill until near end with non ')' so inner loop goes to '\0'
    while (idx < sizeof(start_color) - 1) {
        start_color[idx++] = 'y';
    }
    start_color[idx] = '\0'; // Ensure string termination

    // Reset p to start for the loop
    p = start_color;
}