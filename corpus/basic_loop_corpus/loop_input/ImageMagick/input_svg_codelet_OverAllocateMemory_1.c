#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t length;
size_t extent;

void init_vars() {
    // Set length to a value that ensures the loop runs for approximately 0.01 seconds
    // The loop: for (extent = 256; extent < length; extent *= 2)
    // This loop doubles 'extent' each iteration, so number of iterations is about log2(length) - 8
    // On a modern CPU, each iteration is very fast (a few cycles). To take ~0.01s at ~3GHz, we need roughly 10^7 to 10^8 cycles.
    // Even with 100 cycles per iteration, 10^7 cycles implies ~100k iterations, which would require length ~ 2^(100k+8) — not feasible.
    // Therefore, we conclude the time must come from other effects (e.g., memory access), but the provided loop has no memory ops.
    // Since the loop as given is purely integer arithmetic and will run extremely fast (microseconds even for huge length),
    // we choose a length such that the number of iterations is moderate but non-trivial.

    // However, note: the problem says "suggest 1MB–256MB of input data", implying memory may be involved in full context.
    // But in this loop, there's no array access. So perhaps 'length' corresponds to a data size elsewhere.

    // To align with typical benchmarking, let's assume the intended data size is 64 MB.
    // We set length to 64*1024*1024 (i.e., 67,108,864) to represent 64M elements or bytes.
    length = 67108864;  // 64 * 1024 * 1024

    // 'extent' is initialized inside the loop to 256, so no need to initialize it here beyond zero.
    // But to be safe, we can rely on the loop logic.
}

// Note: The loop function uses only 'length' and 'extent', both now defined.