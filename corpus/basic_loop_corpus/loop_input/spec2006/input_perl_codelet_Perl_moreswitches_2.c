#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *PL_inplace;
char *s;

static char data[131072]; // 128KB of input data

void init_vars() {
    size_t i;
    // Initialize a large buffer with non-whitespace characters except at the end
    for (i = 0; i < sizeof(data) - 1; i++) {
        data[i] = 'a'; // Any non-whitespace character
    }
    data[sizeof(data) - 1] = '\0'; // Null terminate to satisfy *s condition

    // Ensure PL_inplace points to the data buffer
    PL_inplace = data;
    s = NULL; // Will be set in loop(), not needed here
}