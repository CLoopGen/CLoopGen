#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int size;
uint16_t *top;
uint16_t *filtered_top;

void init_vars() {
    size = 64 * 1024 * 1024;  // 64M elements to target ~0.01 sec on modern CPU
    top = (uint16_t*)aligned_alloc(32, (size + 2) * sizeof(uint16_t));
    filtered_top = (uint16_t*)aligned_alloc(32, (size + 2) * sizeof(uint16_t));

    if (!top || !filtered_top) {
        exit(1);
    }

    for (int j = 0; j < size + 2; j++) {
        top[j] = (uint16_t)(j & 0xFFFF);
    }

    i = 2 * size - 2;

    // Ensure loop bounds: i >= 0 and accesses top[i+1], top[i], top[i-1]
    // So we require i-1 >= 0 => i >= 1, but loop stops at i>=0, so minimum i is 0.
    // At i=0: access top[1], top[0], top[-1] -> invalid.
    // Therefore, original loop has bug: it accesses top[i-1] when i can be 0.

    // Adjust so that loop runs safely: we must have i >= 1 at all times when accessing top[i-1].
    // But the loop condition is i >= 0 and starts at 2*size-2.
    // Also note: i-1 must be >= 0 => i >= 1, so loop should stop at i >= 1? But it doesn't.

    // However, given that we cannot change the loop logic, we must ensure that even when i=0, top[-1] is not accessed.
    // But it is accessed. So there's a fundamental issue.

    // Re-examining: loop starts at i = 2*size - 2 and goes down to 0.
    // Accesses: top[i+1], top[i], top[i-1]. For i=0: top[1], top[0], top[-1] -> out of bounds.

    // This suggests the loop body is only valid for i >= 1.
    // But the loop runs for i=0.

    // Since we are told to generate initialization such that memory access does not go out of bounds,
    // we must adjust our data layout or indexing.

    // One solution: shift the base pointer of `top` by 1 so that when the code accesses top[i-1] with i=0,
    // it becomes top[-1] relative to shifted base -> still invalid.

    // Instead, allocate extra padding: we need to allow index from -1 up to 2*size - 1 + 1 = 2*size.
    // Maximum index: i+1 = (2*size - 2) + 1 = 2*size - 1
    // Minimum index: i-1 = 0 - 1 = -1

    // So we need indices from -1 to 2*size - 1 inclusive.

    // Therefore, total buffer size: (2*size - 1) - (-1) + 1 = 2*size + 1
    // We'll allocate that and set top to point to base + 1 so that index -1 in code maps to base[0].

    free(top);
    free(filtered_top);

    const int total_size = 2 * size + 1;
    uint16_t* top_base = (uint16_t*)aligned_alloc(32, total_size * sizeof(uint16_t));
    uint16_t* filtered_base = (uint16_t*)aligned_alloc(32, total_size * sizeof(uint16_t));

    if (!top_base || !filtered_base) {
        exit(1);
    }

    top = top_base + 1;           // Now top[i] corresponds to logical index i, physical index i+1
    filtered_top = filtered_base + 1;

    // Initialize all elements including padding
    for (int j = 0; j < total_size; j++) {
        top_base[j] = (uint16_t)(j & 0xFFFF);
    }
}