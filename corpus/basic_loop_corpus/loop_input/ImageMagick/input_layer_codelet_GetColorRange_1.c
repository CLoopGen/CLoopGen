#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char start_color[262144]; // 256KB buffer
char *p;

void init_vars() {
    // Initialize start_color with a pattern that includes '(' and ')' pairs and ends with '-'
    size_t size = sizeof(start_color) - 1; // Leave space for null terminator
    size_t i = 0;

    while (i < size - 10) { // Reserve space for suffix
        if (rand() % 20 == 0) {
            // Insert a group: "(...)"
            start_color[i++] = '(';
            while (i < size - 2 && rand() % 5 != 0) {
                start_color[i++] = 'a' + (rand() % 26);
            }
            start_color[i++] = ')';
        } else {
            start_color[i++] = 'a' + (rand() % 26);
        }
    }

    // Ensure we don't exceed bounds
    // Add terminal condition: end with '-' followed by '\x00'
    if (i < size) {
        start_color[i++] = '-';
    }
    if (i < size) {
        start_color[i] = '\x00';
    } else {
        start_color[size] = '\x00';
    }

    // Initialize p to start of array
    p = start_color;
}