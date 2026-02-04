#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char start_color[4096];
char *p;

void init_vars() {
    // Initialize start_color with a pattern that ensures the loop runs long enough
    // but terminates safely. We aim for roughly 1-2 million iterations to achieve ~0.01s.
    // Since each iteration advances p, we fill 4096 bytes but structure content to control flow.

    // Fill with printable chars, include '(' and ')' pairs, avoid '-' and '\0' until end
    for (int i = 0; i < 4095; i++) {
        if (i % 128 == 0 && i + 3 < 4095) {
            start_color[i] = '(';
            start_color[i+1] = 'a';
            start_color[i+2] = ')';
            i += 2;
        } else {
            start_color[i] = 'x'; // neutral char
        }
    }
    // Ensure loop termination: place '\0' at end
    start_color[4095] = '\0';

    // Reset p to start
    p = start_color;
}