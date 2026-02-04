#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t length;
size_t extent;

void init_vars() {
    // Set length to a value that ensures the loop runs for approximately 0.01 seconds
    // The loop doubles 'extent' from 256 until it reaches 'length'
    // Number of iterations: log2(length / 256)
    // To get reasonable timing (about 0.01 sec) on modern CPU, aim for ~10M iterations
    // Each iteration is very cheap (just a compare and multiply), so we need large length

    // We choose length = 2^30 (~1 billion) so that:
    // log2(2^30 / 256) = log2(2^30 / 2^8) = log2(2^22) = 22 iterations -> too few

    // Instead, note: the loop itself has no memory access or heavy computation.
    // So even millions of iterations take microseconds. We must simulate intent.

    // But the problem says: "suggest 1MB–256MB of input data"
    // However, no array is used in this loop. Only scalar sizes.

    // Since the loop only uses 'length' and 'extent', and runs in O(log n),
    // to make it run about 0.01 seconds, we cannot rely on large data.

    // Actually, such a short loop (logarithmic) will always be fast.
    // So we pick a large enough 'length' to reflect typical use cases.

    // Let's assume the context involves buffer sizing up to 128MB logical size.
    // But the loop variable 'extent' is likely a buffer capacity, so set length accordingly.

    // Choose length = 134217728 (i.e., 128 * 1024 * 1024)
    length = 134217728;  // 128 MB

    // 'extent' is initialized in the loop, so no need to initialize here beyond what loop does
}

void loop();  // forward declaration

// Ensure that when loop() is called, all variables are initialized
__attribute__((constructor))
static void constructor_init() {
    init_vars();
}