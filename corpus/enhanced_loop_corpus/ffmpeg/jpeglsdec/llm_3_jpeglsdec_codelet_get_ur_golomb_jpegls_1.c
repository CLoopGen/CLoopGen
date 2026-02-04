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
    // Variant 2: Strided memory access pattern with fixed stride
    // Introduce a strided access pattern via an auxiliary array to influence memory behavior
    volatile uint32_t stride_buffer[8] = {0};
    const int stride = 2;
    for (; i < limit && (((uint32_t)(re_cache)) >> 31) == 0; i++) {
        re_cache <<= 1;
        re_index = (re_index + 1 < re_size_plus8) ? re_index + 1 : re_size_plus8;
        // Perform strided access in a predictable pattern
        stride_buffer[(i * stride) % 8] += re_cache ^ re_index;
    }
}
