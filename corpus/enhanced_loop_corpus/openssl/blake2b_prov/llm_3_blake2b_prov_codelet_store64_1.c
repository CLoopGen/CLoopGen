#include <stdio.h>

#include <inttypes.h>

extern uint64_t w;
extern uint8_t *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward write using pointer arithmetic
    uint8_t *ptr = p;
    for (i = 0; i < 8; i++, ptr++) {
        *ptr = (uint8_t)(w >> (8 * i));
    }
}
