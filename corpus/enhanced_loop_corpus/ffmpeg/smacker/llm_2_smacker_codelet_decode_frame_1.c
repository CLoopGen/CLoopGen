#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *out;
extern int i;
extern int stride;
extern uint32_t col;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled loop
    uint32_t *out32 = (uint32_t *)out;
    out32[0] = col;
    out32[1] = col;
    out32[2] = col;
    out32[3] = col;
}
