#include <stdlib.h>
#include <stdint.h>

size_t length;
size_t extent;

void init_vars() {
    // Set length to a value that ensures the loop runs for a noticeable duration
    // The loop: for (extent = 256; extent < length; extent *= 2)
    // This results in O(log n) iterations. To make it run around 0.01 seconds,
    // we need enough iterations. On modern CPUs, each iteration is fast.
    // Let's choose length such that we get tens of millions of iterations?
    // But note: the number of iterations is log2(length/256). So if length is 2^30 (~1GB),
    // then iterations = 30 - 8 = 22. That's too few.

    // However, the loop body is empty — just incrementing extent by doubling.
    // Such a loop will finish in microseconds even for huge lengths.
    // To make it take ~0.01 seconds, we need many more iterations.
    // But this loop only does O(log n) work. So no practical length will make it take 0.01s
    // unless we misinterpret the problem.

    // Wait — perhaps the original loop is meant to be part of a larger context where
    // "length" represents a data size, and we are to simulate realistic scale?
    // The requirement says: "Uses a data size that ensures the original loop runs in approximately 0.01 seconds"

    // But this specific loop is logarithmic. It cannot run for 0.01 seconds without an extremely large number of iterations.
    // For example, 0.01 seconds ≈ 10^7 cycles on a 1GHz CPU. Each iteration is a few cycles.
    // So we'd need ~1e6 iterations. Then:
    //   extent starts at 256, doubles each time: 256 * 2^k >= length
    // We want k ≈ 1e6 → length ≈ 256 * 2^(1e6), which is astronomically huge.

    // Therefore, likely the intention is not to make *this* loop take 0.01s via its own execution,
    // but rather that this loop is representative of one used in a context with large data.
    // So we pick a large but reasonable data size, say 128MB, to reflect typical performance characteristics.

    // Given confusion, we follow common practice: use 64M to 128M elements for medium-large test.

    // Since no array or pointer is actually used in the provided loop code,
    // we simply set `length` to a large value to simulate a real scenario.

    length = 134217728;  // 128 * 1024 * 1024 = 128MB worth of data (if per-byte)
    // Note: though not used as array index here, this sets a meaningful scale.

    // 'extent' is initialized inside the loop, so no need to initialize it here.
    // But to be safe, let init_vars handle all externs.
    extent = 0; // will be overwritten in loop anyway
}