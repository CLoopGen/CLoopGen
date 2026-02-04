#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int limit;
extern unsigned int re_index;
extern __attribute__((unused)) unsigned int re_cache;
extern unsigned int re_size_plus8;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided memory access pattern simulation
    // Introduce a strided access over a synthetic memory region to reflect non-unit stride behavior.
    volatile unsigned int* stride_buffer = (volatile unsigned int*)(((uintptr_t)&re_cache) & ~0x3F); // Align to cache line
    int stride = 2; // Access every 2nd element
    for (; i < limit && stride_buffer[(i * stride) % 16] == 0; i++) {
        re_cache <<= 1;
        re_index = (re_size_plus8 > re_index + 1) ? re_index + 1 : re_size_plus8;
    }
}
