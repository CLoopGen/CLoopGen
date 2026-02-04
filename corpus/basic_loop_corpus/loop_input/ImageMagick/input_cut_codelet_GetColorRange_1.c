#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char start_color[4096];
char *p;

void init_vars() {
    // Initialize the start_color array with data that ensures loop runs for desired time
    // We'll create a pattern that includes nested '(' and ')' pairs and ends with '-' to break early
    size_t size = sizeof(start_color);
    for (size_t i = 0; i < size - 1; i++) {
        if (i % 128 == 0 && i + 10 < size - 1) {
            start_color[i] = '(';
            for (int j = 1; j < 10; j++) {
                start_color[i + j] = 'a' + (j % 26);
            }
            start_color[i + 10] = ')';
            i += 10;
        } else if ((i % 32) == 0) {
            start_color[i] = 'x';
        } else {
            start_color[i] = 'a' + ((i / 7) % 26);
        }
    }
    // Ensure termination condition is met at the end
    start_color[size - 1] = '-';
}