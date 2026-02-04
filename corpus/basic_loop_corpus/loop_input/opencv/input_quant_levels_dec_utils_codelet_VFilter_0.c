#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int w = 10000000; // Approximately 10 million iterations for ~0.01 sec runtime
int x; // Loop index, initialized in loop

void init_vars() {
    // No additional initialization needed for scalar variables
    // They are already defined and initialized at file scope
}