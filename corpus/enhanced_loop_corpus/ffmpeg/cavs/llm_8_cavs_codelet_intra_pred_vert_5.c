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
    for (y = 0; y < 16; y += 2) {
        *((uint64_t *)(d + y * stride)) = a;
        *((uint64_t *)(d + (y + 1) * stride)) = a ^ 0xAAAAAAAA55555555ULL;
    }
}
