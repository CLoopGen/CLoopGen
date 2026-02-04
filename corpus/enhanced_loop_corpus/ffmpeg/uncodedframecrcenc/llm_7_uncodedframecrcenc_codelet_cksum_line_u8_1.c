#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int size;
extern uint8_t *p;
extern unsigned int a;
extern unsigned int b;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    unsigned int local_a = a;
    unsigned int local_b = b;
    uint8_t *temp_p = p;
    for (; size > 0; size--, temp_p++) {
        local_a = (local_a + (unsigned int)(*temp_p) + 1) % 65521;
        local_b = (local_b + local_a) % 65521;
    }
    a = local_a;
    b = local_b;
    p = temp_p;
}
