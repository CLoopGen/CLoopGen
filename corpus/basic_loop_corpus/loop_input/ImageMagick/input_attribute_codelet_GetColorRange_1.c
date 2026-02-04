#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char start_color[4096];
char *p;

void init_vars() {
    // Initialize the start_color array with a pattern that ensures the loop runs long enough
    // but terminates safely. We'll create a large buffer with nested patterns of '(' and ')'
    // to simulate realistic traversal, ensuring we don't exceed bounds.

    const size_t data_size = 1 << 20; // ~1MB of meaningful data to target ~0.01 sec runtime
    for (size_t i = 0; i < 4095 && i < data_size; ++i) {
        if ((i % 17) == 0 && i + 10 < data_size) {
            start_color[i] = '(';
            size_t inner_len = (i % 7) + 1;
            for (size_t j = 1; j <= inner_len; ++j) {
                if (i + j >= 4095) break;
                start_color[i + j] = 'a' + (j % 26);
            }
            if (i + inner_len + 1 < 4095) {
                start_color[i + inner_len + 1] = ')';
                i = i + inner_len + 1;
            }
        } else if ((i % 13) == 0) {
            start_color[i] = '-';
            break;
        } else {
            start_color[i] = 'x';
        }
    }

    // Ensure null termination within bounds
    start_color[4095] = '\0';

    // Initialize p to start of array (will be set by loop logic)
    p = start_color;
}