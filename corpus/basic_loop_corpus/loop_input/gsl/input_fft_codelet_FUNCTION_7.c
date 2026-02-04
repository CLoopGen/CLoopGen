#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t i;
size_t m;

void init_vars() {
    m = 10000000; // Adjusted for approximately 0.01 seconds of loop execution
}

// No main function included as per instructions