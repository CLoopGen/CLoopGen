#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t i;
size_t m;

void init_vars() {
    m = 10000000;  // Adjusted to run loop approximately 10M times for ~0.01 sec on modern CPU
}

// No main function included as per instructions