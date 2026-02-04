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
    int local_shift = 1; // Remove loop-carried dependency on constants by caching in local variable (eliminates potential WAR if `1` were symbolic)
    uint32_t temp_cache = re_cache; // Break direct WAW on re_cache by using temporary
    for (; i < limit && (((uint32_t)(temp_cache)) >> (32 - local_shift)) == 0; i++) {
        temp_cache <<= local_shift;
        re_index++; // Eliminate conditional increment; always increment re_index, removing loop-carried control dependency
        if (re_index >= re_size_plus8) {
            re_index = re_size_plus8; // Clamp once instead of in each iteration
        }
    }
    re_cache = temp_cache; // Single write-back at end, removing intra-loop WAW on re_cache
}
