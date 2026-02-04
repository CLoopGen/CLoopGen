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
    int j;
    for (; i < limit && (((uint32_t)(re_cache)) >> (32 - (2))) == 0; i++) {
        re_cache <<= (2);
        for (j = 0; j < 3; j++) {
            if (re_index < re_size_plus8) {
                re_index++;
            }
        }
    }
}
