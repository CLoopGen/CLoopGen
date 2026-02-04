#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *p;
extern int64_t offset;
extern int in_brackets;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with stride of 2 (simulating non-consecutive access)
    // This variant processes every second character, then adjusts offset accordingly
    int64_t stride = 2;
    int64_t i = offset;

    for (; ; ) {
        if (i >= offset && (p[i] == ' ' || p[i] == '\t')) {
            i += stride;
        } else if (i >= offset && p[i] == '[') {
            i += stride;
            in_brackets++;
        } else if (i >= offset && p[i] == ']' && in_brackets) {
            i += stride;
            in_brackets--;
        } else if (in_brackets && i >= offset && (p[i] == ':' || p[i] == '.' || p[i] == '-' || (p[i] >= '0' && p[i] <= '9'))) {
            i += stride;
        } else {
            break;
        }
    }
    // Update the global offset to reflect progress (approximate based on stride behavior)
    if (i > offset) {
        offset = i - stride + 1;  // Conservative update to avoid skipping
    }
}
