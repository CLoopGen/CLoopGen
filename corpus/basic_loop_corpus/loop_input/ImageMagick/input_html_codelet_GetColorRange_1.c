#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char start_color[4096];
char *p;

void init_vars() {
    // Initialize start_color with a pattern that ensures the loop runs long enough
    // to meet the ~0.01 second runtime target. Since the original array is only 4096 bytes,
    // we need to simulate larger data by repeating the loop logic or adjusting workload.
    // However, the array size is fixed at 4096, so we must design content to maximize
    // traversal time within this limit.

    // Fill with nested parentheses and non-terminating characters to force deep scanning
    int pos = 0;
    const int size = 4096;

    while (pos < size - 32) {
        if (pos + 20 < size) {
            start_color[pos++] = '(';
            for (int j = 0; j < 18 && pos < size - 1; j++) {
                start_color[pos++] = 'a' + (j % 26);
            }
            start_color[pos++] = ')';
        } else {
            break;
        }
    }

    // Fill remaining space with non-matching characters
    while (pos < size - 1) {
        start_color[pos++] = 'x';
    }

    // Ensure termination with '-' at the very end to prevent infinite loop
    start_color[size - 1] = '-';

    // Initialize p to start of array (will be overwritten on first loop call anyway)
    p = start_color;
}