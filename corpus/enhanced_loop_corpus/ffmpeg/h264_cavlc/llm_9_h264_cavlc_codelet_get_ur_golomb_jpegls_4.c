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
    int step = 2;
    for (; i < limit && (((uint32_t)(re_cache)) >> (32 - (1))) == 0; i += step) {
        re_cache <<= (1);
        re_index += (1);
        if (i % 4 == 0) {
            re_cache += (re_cache >> 4); // Extra computation every few iterations
        }
    }
}
