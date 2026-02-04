#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char start_color[4194304]; // 4MB buffer to ensure ~0.01s runtime
char *p;

void init_vars() {
    // Initialize start_color with a pattern that includes '(' and ')' pairs and ends with '-'
    size_t pos = 0;
    const size_t max_size = sizeof(start_color) - 256; // Leave room for terminator
    while (pos < max_size) {
        if (rand() % 100 < 15) { // 15% chance to insert a parenthesized group
            start_color[pos++] = '(';
            // Fill inner content until closing ')'
            while (pos < max_size && rand() % 100 < 70) {
                start_color[pos++] = 'a' + (rand() % 26);
            }
            if (pos < max_size) {
                start_color[pos++] = ')';
            }
        } else {
            // Normal character or terminate condition
            char c = rand() % 100 < 5 ? '-' : ('a' + (rand() % 26));
            start_color[pos++] = c;
            if (c == '-') break;
        }
    }
    // Ensure null termination before array end
    if (pos >= sizeof(start_color)) pos = sizeof(start_color) - 1;
    start_color[pos] = '\x00';
}