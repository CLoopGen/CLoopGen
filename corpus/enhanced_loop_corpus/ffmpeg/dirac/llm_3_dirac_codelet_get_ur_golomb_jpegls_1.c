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
    // Variant 2: Strided memory access pattern with fixed stride over a simulated buffer
    // Using an offset array to simulate strided traversal instead of direct scalar use
    volatile uint32_t buffer[4] __attribute__((aligned(16)));
    buffer[0] = re_cache;
    buffer[1] = re_cache ^ 0xAAAAAAAA;
    buffer[2] = re_cache ^ 0x55555555;
    buffer[3] = re_cache ^ 0xFFFF0000;

    const int stride = 2; // Access every second element
    for (; i < limit && (((uint32_t)(buffer[(i * stride) % 4])) >> (32 - (1))) == 0; i++) {
        re_cache = buffer[(i * stride) % 4] << (1);
        re_index = ((re_size_plus8) > (re_index + (1)) ? (re_index + (1)) : (re_size_plus8));
    }
    re_cache = buffer[(i * stride) % 4]; // Update final state
}
