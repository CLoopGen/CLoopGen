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
    // Variant 2: Strided memory access pattern using synthetic stride over bit manipulation
    // Simulate strided traversal by skipping bits in chunks of 4 (stride of 4)
    int stride = 4;
    int shift_amount = 1;
    for (; i < limit && (((uint32_t)(re_cache)) >> (32 - shift_amount)) == 0; i += stride) {
        re_cache <<= shift_amount * stride;
        re_index = (re_size_plus8 > re_index + stride) ? re_index + stride : re_size_plus8;
        // Ensure index doesn't exceed synthetic bounds
        if (re_index >= re_size_plus8) {
            re_index = re_size_plus8;
        }
    }
    // Cleanup pass for remaining iterations if needed, without while
    for (; i < limit && (((uint32_t)(re_cache)) >> (32 - shift_amount)) == 0; i++) {
        re_cache <<= shift_amount;
        re_index = (re_size_plus8 > re_index + 1) ? re_index + 1 : re_size_plus8;
    }
}
