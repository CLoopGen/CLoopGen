#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int offset[8];

void init_vars() {
    // Initialize variables if needed; in this case, they are global and zero-initialized by default
    // Ensure no out-of-bounds access: loop runs from i=3 to i<8, which is valid for offset[8]
    // Data size is negligible here (only 8 ints), but no large data required as per loop logic
}