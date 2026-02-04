#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char start_color[4096];
char *p;

void init_vars() {
    // Initialize start_color with a pattern that ensures the loop runs for a predictable amount of time
    // We aim for approximately 0.01 seconds of execution, which on modern CPUs may correspond to several million iterations.
    // Since the array is only 4096 bytes, we design the content to cause the loop to traverse most of it.

    memset(start_color, 'X', sizeof(start_color));

    // Place '(' and ')' pairs to trigger inner loop logic
    int pos = 0;
    while (pos < (int)(sizeof(start_color) - 256)) {
        start_color[pos] = '(';
        pos++;
        int len = 30 + (pos % 23); // Vary inner length
        memset(start_color + pos, 'Y', len);
        pos += len;
        if (pos >= (int)(sizeof(start_color) - 1)) break;
        start_color[pos] = ')';
        pos++;
    }

    // Ensure the last part ends with '-' to stop outer loop naturally
    start_color[sizeof(start_color) - 1] = '-';
}