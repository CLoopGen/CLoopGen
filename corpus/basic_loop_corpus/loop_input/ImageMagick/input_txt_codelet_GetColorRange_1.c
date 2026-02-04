#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char start_color[4096];
char *p;

void init_vars() {
    // Initialize the start_color array with data that ensures meaningful traversal
    // The array size is fixed at 4096 as per declaration, so we fill it appropriately.
    // We aim for realistic execution time (~0.01s), but given the small fixed size (4KB),
    // the loop will be very fast; however, this matches the declared array size.

    // Fill with pattern to trigger the logic: include '(', ')', '-', and '\0'
    // We'll place a few nested structures and ensure termination conditions are met

    for (int i = 0; i < 4096; i++) {
        start_color[i] = 'a' + (i % 23);  // Fill mostly with letters
    }

    // Insert some '(' and ')' groups
    int pos = 0;
    while (pos < 4096 - 100) {
        start_color[pos] = '(';
        pos++;
        for (int j = 0; j < 10 && pos < 4096 - 1; j++, pos++) {
            start_color[pos] = 'x';
        }
        if (pos < 4096 - 1) {
            start_color[pos++] = ')';
        }
    }

    // Place '-' near the end to act as termination condition
    if (pos < 4096 - 1) {
        start_color[pos + 50] = '-';
    }

    // Ensure null terminator at the end
    start_color[4095] = '\0';

    // Initialize p to start of array (will be overwritten on first loop call anyway)
    p = start_color;
}