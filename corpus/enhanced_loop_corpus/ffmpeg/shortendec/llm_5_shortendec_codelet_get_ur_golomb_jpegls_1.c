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
    for (; i < limit; i++) {
        uint32_t shifted = ((uint32_t)(re_cache)) >> 31;
        if (shifted != 0) {
            break;
        }
        re_cache <<= 1;
        re_index = (re_index + 1 >= re_size_plus8) ? re_size_plus8 : re_index + 1;
    }
}
