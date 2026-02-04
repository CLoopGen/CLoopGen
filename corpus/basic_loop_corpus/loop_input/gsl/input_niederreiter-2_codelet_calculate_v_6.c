#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int v[65536];
int arbitrary_element = 42;
int m = 65536;
int r;
int kj = 0;

void init_vars() {
    // Ensure m is within array bounds
    if (m > 65536) {
        m = 65536;
    }
    // Initialize arbitrary_element to a known value
    arbitrary_element = 12345;
    // Set kj to ensure the loop runs for a significant number of iterations
    kj = 10;
    m = 65536; // Full array size for sufficient workload
}