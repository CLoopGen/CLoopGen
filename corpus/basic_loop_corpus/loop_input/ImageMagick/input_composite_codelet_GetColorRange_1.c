#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char start_color[4096];
char *p;

void init_vars() {
    // Initialize start_color with a pattern that ensures realistic execution behavior
    // Fill with printable characters, including '(', ')', '-', and other chars
    // Ensure the array is null-terminated and contains no out-of-bounds access

    size_t size = sizeof(start_color);
    for (size_t i = 0; i < size - 1; i++) {
        if (i % 128 == 0 && i + 1 < size - 1) {
            start_color[i] = '(';
            start_color[i+1] = 'a';
            start_color[i+2] = ')';
            i += 2;
        } else if (i % 64 == 0) {
            start_color[i] = '-';
        } else {
            start_color[i] = "abcdefghijklmnopqrstuvwxyz"[i % 26];
        }
    }
    start_color[size - 1] = '\0';  // Ensure null termination
}