#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *d;
extern ptrdiff_t stride;
extern int y;
extern uint64_t a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < 4; y++) {
        uint8_t *p1 = d + y * stride;
        uint8_t *p2 = d + (y + 4) * stride;
        *((uint64_t *)p1) = a;
        *((uint64_t *)p2) = a + y;
    }
}
