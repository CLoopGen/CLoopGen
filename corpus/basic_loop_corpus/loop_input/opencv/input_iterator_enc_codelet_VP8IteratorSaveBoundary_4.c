#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;

void init_vars() {
    // No additional initialization needed for variable 'i'
    // It is a simple integer used as a loop counter in the provided loop.
    // The loop uses i = 0; i < 8; ++i, which is self-contained.
    // Ensure i is in valid state if needed before loop entry.
    i = 0;
}