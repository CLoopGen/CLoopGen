#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t loop_lim = 200000000; // Approximate size for ~0.01 sec on modern CPU
size_t i;

void init_vars() {
    // No additional initialization needed for scalar variables
    // Values are already defined at file scope
}