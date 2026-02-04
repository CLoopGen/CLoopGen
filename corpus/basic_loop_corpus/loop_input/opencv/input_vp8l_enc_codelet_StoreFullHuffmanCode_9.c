#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int num_tokens = 10000000; // Sufficient size to run loop for ~0.01 seconds
int i = 0;

void init_vars() {
    // No dynamic initialization required for basic integer variables
    // Values are already set at file scope
}