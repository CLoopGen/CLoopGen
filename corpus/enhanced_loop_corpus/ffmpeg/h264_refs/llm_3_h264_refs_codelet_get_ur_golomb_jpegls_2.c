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
    // Variant 2: Strided memory access pattern with fixed stride over a synthetic buffer
    // Instead of linear progression, access memory locations separated by a constant stride
    const int stride = 8;
    volatile unsigned int buffer[16] = {0}; // Synthetic buffer for strided access
    volatile unsigned int* buf_ptr = (volatile unsigned int*)(&re_cache);

    for (; i < limit && (((uint32_t)(re_cache)) >> 31) == 0; i++) {
        re_cache <<= 1;
        re_index = (re_index + 1) >= re_size_plus8 ? re_size_plus8 : (re_index + 1);

        // Perform strided access on synthetic buffer (wrap-around within bounds)
        int idx = (i * stride) % 16;
        buffer[idx] += 1; // Simulate meaningful strided write
        buf_ptr = &buffer[idx];
    }
}
