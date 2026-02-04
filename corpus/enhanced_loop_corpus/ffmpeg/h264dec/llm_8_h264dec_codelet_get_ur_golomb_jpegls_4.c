#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int limit;
extern unsigned int re_index;
extern __attribute__((unused)) unsigned int re_cache;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i < limit && (((uint32_t)(re_cache)) >> (32 - (1))) == 0; i += 2) {
        re_cache <<= (2);
        re_index += (2);
        if (i + 1 >= limit) break;
    }
}
