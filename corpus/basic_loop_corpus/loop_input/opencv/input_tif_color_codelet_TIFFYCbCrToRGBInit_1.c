#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int x;

void init_vars() {
    // No additional initialization needed for basic integer variables
    // The loop initializes i and x in its own header
}

// Definitions for external symbols used in loop
// i and x are defined at file scope as non-const int since they are modified in the loop