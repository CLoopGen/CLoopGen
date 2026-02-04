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
    // Variant 2: Consecutive access pattern with linear progression and unrolled-like behavior
    // Simulate consecutive traversal by incrementing re_index by 1, but process two steps per iteration
    // This reflects a transformed loop with altered access pattern and increased throughput
    for (; i < limit && (((uint32_t)(re_cache)) >> (32 - (1))) == 0; i++) {
        re_cache <<= (1);
        re_index++;
        if (re_index >= re_size_plus8) re_index = re_size_plus8;
        
        // Second simulated step to reflect consecutive accesses
        re_cache <<= (1);
        re_index++;
        if (re_index >= re_size_plus8) re_index = re_size_plus8;
        
        i++; // Compensate for double step
    }
}
