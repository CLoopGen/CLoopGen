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
    unsigned int local_cache = re_cache;
    unsigned int local_index = re_index;
    for (; i < limit && (((uint32_t)(local_cache)) >> (32 - (1))) == 0; i++) {
        local_cache <<= (1);
        local_index = (re_size_plus8 > (local_index + (1)) ? (local_index + (1)) : (re_size_plus8));
    }
    re_cache = local_cache;
    re_index = local_index;
}
