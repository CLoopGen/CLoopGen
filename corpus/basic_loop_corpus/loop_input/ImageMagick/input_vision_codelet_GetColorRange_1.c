#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char start_color[268435456]; // 256MB buffer
char *p;

void init_vars() {
    size_t size = sizeof(start_color) - 1; // Leave space for null terminator
    char *ptr = start_color;
    size_t i = 0;

    while (i < size - 100) {
        // Randomly decide to insert a '(' ... ')' block or plain characters
        if (rand() % 5 == 0) {
            ptr[i++] = '(';
            while (i < size - 1 && ptr[i-1] != ')') {
                ptr[i++] = 'a' + (rand() % 26);
                // 10% chance to end the group
                if (rand() % 10 == 0) {
                    ptr[i-1] = ')';
                }
            }
            if (ptr[i-1] != ')') {
                ptr[i++] = ')';
            }
        } else {
            // Insert regular character, avoid '-' and '\0'
            char c;
            do {
                c = 'a' + (rand() % 26);
            } while (c == '-');
            ptr[i++] = c;
        }
    }

    // Ensure termination by '-' or '\0' at some point within last 100 bytes
    int terminate_with_dash = rand() % 2;
    if (terminate_with_dash) {
        ptr[i++] = '-';
    } else {
        // Add closing ')' if we have unclosed group
        size_t depth = 0;
        for (size_t j = 0; j < i; j++) {
            if (ptr[j] == '(') depth++;
            if (ptr[j] == ')' && depth > 0) depth--;
        }
        while (depth > 0) {
            ptr[i++] = ')';
            depth--;
        }
        // Terminate with null
        ptr[i++] = '\0';
    }

    // Zero out rest
    while (i < size + 1) {
        ptr[i++] = '\0';
    }

    // Initialize p to start of array
    p = start_color;
}