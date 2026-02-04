#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int size;
extern int16_t *p;
extern unsigned int a;
extern unsigned int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int local_a = a;
    unsigned int local_b = b;
    for (; size > 0; size--, p++) {
        local_a = (local_a + (unsigned int)(*p + 16384)) % 65521;
        local_a = (local_a + (unsigned int)(*p + 16384)) % 65521; // Double addition to increase computation per iteration
        local_b = (local_b + local_a) % 65521;
    }
    a = local_a;
    b = local_b;
}
