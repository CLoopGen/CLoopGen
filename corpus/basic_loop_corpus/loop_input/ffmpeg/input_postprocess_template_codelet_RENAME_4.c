#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int x;

void init_vars() {
    // Initialize variables to ensure loop runs with valid state
    // The loop runs for 2 iterations, so no large data needed
    // Only scalar variable 'x' is involved and it's modified in the loop
    // No array or pointer accesses observed in loop body
    // Thus, minimal initialization is sufficient
    x = 0;
}