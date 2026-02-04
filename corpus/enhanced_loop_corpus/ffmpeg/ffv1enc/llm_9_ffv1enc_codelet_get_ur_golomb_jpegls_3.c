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
    // Variant 2: Reduced computational intensity with expanded trip count and simplified logic
    // The condition is relaxed to allow more iterations, but each iteration does less
    int expanded_limit = (limit < 1000) ? limit * 2 : limit;  // Avoid excessive expansion
    for (; i < expanded_limit && (((uint32_t)(re_cache)) >> (31)) == 0; i++) {
        re_cache <<= 1;
        // Simplified index update without conditional check
        re_index++;
        // Bound check after increment instead of ternary operation
        if (re_index >= re_size_plus8) {
            re_index = re_size_plus8;
        }
    }
}
