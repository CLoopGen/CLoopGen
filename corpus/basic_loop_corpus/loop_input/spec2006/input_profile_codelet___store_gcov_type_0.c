#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <sys/time.h>

typedef long gcov_type;

gcov_type value;
char *dest;
size_t bytes;
size_t i;

void init_vars() {
    // Set data size to achieve approximately 0.01 seconds runtime
    // Based on typical performance, ~64MB should be in the right range
    // for a loop with division and conditional bit masking
    bytes = 64 * 1024 * 1024;  // 64 MB

    // Allocate memory for dest
    dest = (char *)malloc(bytes);
    if (!dest) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize value to a large number to ensure full propagation across bytes
    value = 0xABCDEF123456789AL;  // Arbitrary large value

    // Ensure that we don't read/write out of bounds
    // The loop uses `sizeof(value)` which is typically 8 for 'long' on 64-bit
    // So clamp bytes to at most sizeof(value) if needed, but here we let the loop condition handle it
}