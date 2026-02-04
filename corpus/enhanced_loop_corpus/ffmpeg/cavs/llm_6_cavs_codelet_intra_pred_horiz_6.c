#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *d;
extern uint8_t *left;
extern ptrdiff_t stride;
extern int y;
extern uint64_t a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t temp[8];
    for (y = 0; y < 8; y++) {
        temp[y] = left[y + 1] * 72340172838076673ULL;
    }
    for (y = 0; y < 8; y++) {
        *((uint64_t *)(d + y * stride)) = temp[y];
    }
}
