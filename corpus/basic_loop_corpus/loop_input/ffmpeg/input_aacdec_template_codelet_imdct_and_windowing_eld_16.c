#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int n = 50000000; // Ensures loop runs approx. 25M iterations with i += 2, targeting ~0.01 sec on modern CPU

void init_vars() {
    // No dynamic initialization required for scalar variables
    // All necessary variables are already defined at file scope with appropriate initial values
}