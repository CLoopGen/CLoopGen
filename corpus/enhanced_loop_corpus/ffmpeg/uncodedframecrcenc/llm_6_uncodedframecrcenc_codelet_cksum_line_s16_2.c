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
    uint32_t temp_a = a;
    uint32_t temp_b = b;
    int16_t *local_p = p;
    unsigned int local_size = size;

    for (; local_size > 0; local_size--, local_p++) {
        temp_a = (temp_a + (unsigned int)(*local_p + 32768)) % 65521;
        temp_b = (temp_b + temp_a) % 65521;
    }

    a = temp_a;
    b = temp_b;
    p = local_p;
    size = local_size;
}
