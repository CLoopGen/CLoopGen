#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;

void init_vars() {
    // No additional initialization needed for scalar variables
    // since 'i' is modified directly in the loop.
}
// The loop uses only the global variable 'i', which is declared as int.
// No arrays or other data structures are accessed in the loop,
// so no large data allocations are necessary.
// The loop runs exactly 4 iterations, bounded safely by the condition i < 4.