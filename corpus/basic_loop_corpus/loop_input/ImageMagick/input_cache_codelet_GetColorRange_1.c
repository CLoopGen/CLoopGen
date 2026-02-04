#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

char start_color[4096];
char *p;

void init_vars() {
    // Initialize start_color with a pattern that ensures safe and controlled loop execution
    // The data size is fixed at 4096 bytes as defined by the array declaration
    // We construct a string with nested patterns to simulate realistic traversal behavior

    memset(start_color, 0, sizeof(start_color));

    // Construct a long sequence of characters to trigger meaningful loop behavior
    // Pattern: repeat blocks like "abc(defg)hij" to exercise both loops
    char *ptr = start_color;
    size_t total = 0;
    const size_t block_size = 10;
    const size_t n_blocks = (sizeof(start_color) - 64) / block_size; // Leave room for terminator

    for (size_t i = 0; i < n_blocks && total + block_size + 1 < sizeof(start_color) - 1; i++) {
        if (i % 7 == 0) {
            // Occasionally insert a '(' without ')' to test break condition
            ptr[0] = '(';
            ptr[1] = 'a';
            ptr[2] = 'b';
            ptr[3] = 'c';
            ptr += 4;
            total += 4;
        } else {
            // Normal block with balanced parentheses
            ptr[0] = 'x'; ptr[1] = 'y'; ptr[2] = 'z';
            ptr[3] = '(';
            ptr[4] = 'd'; ptr[5] = 'e'; ptr[6] = 'f';
            ptr[7] = ')';
            ptr[8] = 'p'; ptr[9] = 'q';
            ptr += block_size;
            total += block_size;
        }
    }

    // Ensure we terminate before end
    while (total + 1 >= sizeof(start_color)) {
        total--;
        ptr--;
    }

    *ptr = '-';
    *(ptr + 1) = '\0';

    // Initialize p to start of array (will be overwritten when loop starts)
    p = start_color;
}