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



void loop(){
    int step = 2;
    for (; i < limit && (((uint32_t)(re_cache)) >> (32 - (1))) == 0; i += step) {
        re_cache <<= (2);  // Double shift per iteration
        re_index = (re_index + 2 < re_size_plus8) ? re_index + 2 : re_size_plus8;
        // Reduced trip count by stepping through loop faster
        // Increased arithmetic per iteration with larger shifts and index jumps
        // Simulates higher throughput, lower iteration count variant
    }
}
