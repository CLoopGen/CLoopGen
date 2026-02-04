#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t i;

void init_vars() {
    // No initialization needed for loop counter 'i' as it is set in the loop
    // Data size and bounds are controlled by the loop itself (0 to 1026)
    // No arrays or pointers accessed in the loop, so no dynamic allocation required
}