#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t length;
size_t extent;

void init_vars() {
    length = 100 * 1024 * 1024; // 100 MB to ensure loop runs for desired duration
    extent = 256;
}

void loop(); // forward declaration

// Ensure the loop can be called from other translation units
// The actual loop implementation is in another file