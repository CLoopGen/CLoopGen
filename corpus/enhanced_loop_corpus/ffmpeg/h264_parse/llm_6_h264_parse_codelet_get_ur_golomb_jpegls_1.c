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
    int temp_re_index = re_index;
    uint32_t temp_re_cache = re_cache;
    for (; i < limit && (((uint32_t)(temp_re_cache)) >> (32 - (1))) == 0; i++) {
        temp_re_cache <<= (1);
        temp_re_index = (re_size_plus8 > temp_re_index + (1)) ? (temp_re_index + (1)) : re_size_plus8;
    }
    re_index = temp_re_index;
    re_cache = temp_re_cache;
}
