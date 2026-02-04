#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char start_color[4096];
char *p;

void init_vars() {
    // Initialize the start_color array with a pattern that ensures the loop runs for a significant time
    // but terminates safely. We'll create a large buffer (close to 4096 bytes) with nested patterns.
    size_t len = sizeof(start_color);
    for (size_t i = 0; i < len - 1; i++) {
        if (i % 128 == 0 && i + 10 < len) {
            start_color[i] = '(';
            i++;
            while (i < len - 1 && i % 128 != 0) {
                start_color[i] = 'a';
                i++;
            }
            if (i < len - 1) {
                start_color[i] = ')';
            } else {
                start_color[len - 2] = ')';
                break;
            }
        } else {
            start_color[i] = 'x';
        }
    }
    // Ensure termination condition near the end
    start_color[len - 1] = '-';
}