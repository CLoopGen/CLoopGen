#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;

void init_vars() {
    // No additional initialization needed for scalar variables
    // since 'i' is modified in the loop and has automatic meaning in its context.
    // All extern variables are already defined at file scope.
}
// No array or large data required — loop runs only 2 iterations regardless of data size.
// The loop does not access any memory or use any complex data structures.
// Thus, no large buffers or dynamic allocation is necessary.