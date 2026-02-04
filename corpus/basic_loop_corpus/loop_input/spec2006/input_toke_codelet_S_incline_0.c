#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *s;
char *t;

static char data[1 << 24]; // 16 MB buffer

void init_vars() {
    // Initialize the data array with non-whitespace characters followed by a space
    for (size_t i = 0; i < sizeof(data) - 1; i++) {
        data[i] = 'a'; // Arbitrary non-whitespace character
    }
    data[sizeof(data) - 1] = ' '; // Terminate with space to break the loop

    // Initialize s to point to the beginning of data
    s = data;
    t = NULL; // Will be set in loop(), do not initialize here
}