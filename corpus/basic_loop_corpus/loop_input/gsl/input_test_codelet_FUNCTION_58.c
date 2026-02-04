#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

size_t i;

void init_vars() {
    // No additional initialization needed for scalar loop index
    // Loop bounds (0 to 1026) are safe and within typical range
    // No arrays or pointers accessed in loop, so no large data allocations required
    // The loop runs 1027 iterations, which is sufficient to meet runtime target
    // without large data structures.
    i = 0;
}