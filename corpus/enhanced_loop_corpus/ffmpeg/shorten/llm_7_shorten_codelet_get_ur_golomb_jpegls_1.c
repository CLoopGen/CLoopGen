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
    int local_shift = 1;
    uint32_t temp_cache = re_cache;
    for (; i < limit && (((uint32_t)(temp_cache)) >> (32 - local_shift)) == 0; i++) {
        temp_cache <<= local_shift;
        re_index += local_shift; // Remove direct loop-carried dependency on previous re_index in condition
        if (re_index >= re_size_plus8) {
            re_index = re_size_plus8;
        }
    }
    re_cache = temp_cache; // Update shared state only after loop
}
