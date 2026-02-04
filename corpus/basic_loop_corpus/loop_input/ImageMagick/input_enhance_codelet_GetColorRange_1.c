#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char start_color[262144]; // 256KB data to ensure ~0.01s runtime
char *p;

void init_vars() {
    // Initialize start_color with pattern to control loop behavior
    size_t size = sizeof(start_color);
    for (size_t i = 0; i < size - 1; i++) {
        if (i % 100 == 0 && i + 50 < size) {
            start_color[i] = '(';
            for (int j = 1; j < 49 && i + j < size - 1; j++) {
                start_color[i + j] = 'a' + (j % 26);
            }
            start_color[i + 49] = ')';
            i += 49;
        } else if (i == size - 2) {
            start_color[i] = '-';
        } else {
            start_color[i] = 'a' + (i % 26);
        }
    }
    start_color[size - 1] = '\x00'; // Null terminate

    p = start_color; // Initial value for p
}