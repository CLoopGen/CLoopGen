#include <inttypes.h>

int i;

void init_vars() {
    // No additional initialization needed for scalar variables
    // Loop bounds in 'loop' function are fixed and do not depend on runtime data
    i = 0; // Ensure initial state consistency
}