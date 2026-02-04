#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t length;
size_t extent;

void init_vars() {
    // Set length to ensure the loop runs for approximately 0.01 seconds
    // The loop: for (extent = 256; extent < length; extent *= 2)
    // This loop runs in logarithmic time (base 2 from 256 to length), so number of iterations is log2(length) - 8.
    // To make it take ~0.01s, we need enough iterations. Modern CPUs do billions of ops/sec,
    // but this loop is very simple (multiply by 2). Let's aim for about 10M iterations -> 10M ns = 0.01s.
    // But since it's only multiplications and comparisons, each iteration is a few cycles.
    // So even 30 iterations takes negligible time. Therefore, we must choose a large length
    // not to slow the loop, but to satisfy data size requirements.

    // The problem says: "use data size 1MB–256MB". Since no array is used in the provided loop,
    // but external context may expect memory, we assume 'length' relates to a data buffer elsewhere.
    // We'll set length to 64MB to fit within suggested range.

    length = 64 * 1024 * 1024;  // 64 MB
}

// No main() included as per instructions