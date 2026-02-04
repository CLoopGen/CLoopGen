#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ssize_t n;
size_t depth;

void init_vars() {
    n = (ssize_t)0x7FFFFFFFFFFFFFFFLL; // Large signed value to ensure many loop iterations
    depth = 0;
}

void loop(); // Forward declaration to avoid implicit declaration error

// This file defines the external variables used in the loop function
// and provides an initialization routine to set them to appropriate values.