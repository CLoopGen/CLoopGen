#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char start_color[4096];
char *p;

void init_vars() {
    // Initialize start_color with data that ensures loop runs for desired time
    // Target ~0.01 seconds: use large data, but start_color is fixed at 4096 bytes.
    // We'll fill it with patterns that cause deep traversal: many '(' and ')'
    
    size_t i = 0;
    // Fill most of the buffer with regular characters
    for (; i < 4080; i++) {
        if (i % 20 == 0 && i + 5 < 4080) {
            // Insert a group: '(' followed by non-')' then ')'
            start_color[i] = '(';
            start_color[i+1] = 'a';
            start_color[i+2] = 'b';
            start_color[i+3] = 'c';
            start_color[i+4] = ')';
            i += 4;
        } else {
            start_color[i] = 'x'; // normal char, not special
        }
    }
    // Ensure we don't hit '-' or '\0' too early
    // Place a '-' near the end to stop the outer loop naturally
    start_color[4080] = 'x';
    start_color[4081] = 'x';
    start_color[4082] = '-';
    for (i = 4083; i < 4095; i++) {
        start_color[i] = 'x';
    }
    start_color[4095] = '\0'; // null terminate

    // Initialize p to start of start_color
    p = start_color;
}