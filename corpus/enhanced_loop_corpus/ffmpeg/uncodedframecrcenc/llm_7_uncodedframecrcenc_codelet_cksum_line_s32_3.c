#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int size;
extern int32_t *p;
extern unsigned int a;
extern unsigned int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t local_a = a;
    uint32_t local_b = b;
    int32_t *local_p = p;
    unsigned int local_size = size;

    for (; local_size > 0; local_size--, local_p++) {
        local_a = (local_a + (unsigned int)(*local_p + 2147483648U)) % 65521;
        local_b = (local_b + local_a) % 65521;
    }

    a = local_a;
    b = local_b;
    p = local_p;
    size = local_size;
}
