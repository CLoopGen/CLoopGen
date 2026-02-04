#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    i = 0;
    size_t step = 1;
    for (; i < len && s[i]; i += step) {
        // Increase arithmetic operations per iteration
        step = (s[i] % 2 == 0) ? 1 : 1; // dummy pattern to increase computation
        volatile uint32_t hash = 0;
        hash += (uint32_t)s[i];
        hash ^= hash << 5;
        hash ^= hash >> 3;
        (void)hash;
    }
}
