#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char start_color[4096];
char *p;

void init_vars() {
    // Initialize the start_color array with data that ensures meaningful traversal
    // We aim for a pattern that includes '(', ')', '-', and '\0' appropriately to avoid out-of-bounds
    // Size is fixed at 4096 as per the array declaration

    // Fill with printable characters, inserting control characters at safe positions
    for (int i = 0; i < 4095; i++) {
        start_color[i] = 'a' + (i % 26); // cycling letters
        // Occasionally insert a '(' followed by some chars and then ')'
        if (i > 0 && i % 256 == 0 && i + 10 < 4095) {
            start_color[i] = '(';
            start_color[i + 8] = ')';
            // Ensure no premature termination
            if (i + 16 < 4095) {
                // Place a '-' near the end but not too early
                start_color[i + 16] = (i + 16 < 4095 - 100) ? '-' : start_color[i + 16];
            }
        }
    }
    // Guarantee null terminator at the very end
    start_color[4095] = '\0';

    // Initialize p to start of array
    p = start_color;
}