#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char start_color[262144] __attribute__((aligned(4096)));
char *p;

void init_vars() {
    size_t size = sizeof(start_color);
    char *data = start_color;
    
    // Fill with mostly normal characters, include some '(' and ')' pairs, and ensure ends with '-' or '\0'
    memset(data, 'a', size);
    
    // Place several parentheses groups
    int pos = 100;
    for (int i = 0; i < 50 && pos + 20 < size - 100; i++) {
        data[pos] = '(';
        pos += 1;
        for (int j = 0; j < 15; j++, pos++) {
            if (pos >= size - 100) break;
            data[pos] = 'x';
        }
        if (pos < size - 100) {
            data[pos] = ')';
            pos += 7; // Skip forward to avoid immediate matching
        }
    }
    
    // Ensure loop termination condition near the end
    // Leave a gap then place '-' to trigger early exit
    size_t terminate_pos = size - 64;
    data[terminate_pos] = '-';
    
    // Guarantee null termination somewhere after potential scan
    data[size - 1] = '\0';
}