#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;

void init_vars() {
    // No initialization needed for scalar variable 'i'
    // It is used as a loop counter in the provided loop and does not require pre-initialization
    // The loop uses i from 0 to 7, which is safe and within bounds
}