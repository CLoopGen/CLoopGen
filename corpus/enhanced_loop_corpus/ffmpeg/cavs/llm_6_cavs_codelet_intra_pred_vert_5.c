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
    uint64_t temp = a;
    for (y = 0; y < 8; y++) {
        temp += y; // Introduce local dependency: each iteration modifies 'temp' used in next
        *((uint64_t *)(d + y * stride)) = temp;
    }
}
