#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int limit;
unsigned int re_index;
__attribute__((unused)) unsigned int re_cache;
unsigned int re_size_plus8;
int i;

void init_vars() {
    // Initialize variables to ensure the loop runs for a measurable duration
    // The loop condition involves bit shifting and index bounds, so we set parameters accordingly

    // Set re_cache to have high bits zero so the loop condition ((re_cache >> 31) == 0) is initially true
    re_cache = 0x7FFFFFFF;  // High bit is 0, so (32 - 1) = 31 shift gives 0

    // We want the loop to run long enough to take ~0.01 seconds
    // Each iteration does a left shift by 1 and increments re_index until it hits re_size_plus8
    // The inner do-while is actually just a single operation due to while(0)

    // To control runtime, set limit to about 1 million iterations (typical modern CPU: millions of ops/sec)
    limit = 1000000;

    // Start re_index at 0
    re_index = 0;

    // Set re_size_plus8 to a value larger than any re_index will reach (e.g., > 1M)
    re_size_plus8 = 2000000;

    // Start loop counter i at 0
    i = 0;
}