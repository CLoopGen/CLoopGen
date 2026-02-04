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
    int step = 1;
    for (; i < limit && (((uint32_t)(re_cache)) >> (32 - step)) != 0; i++) {
        re_cache <<= (step);
        re_index += (step);
        step = (step == 1) ? 2 : 1;
    }
}
