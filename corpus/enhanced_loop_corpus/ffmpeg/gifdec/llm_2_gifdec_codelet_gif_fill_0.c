#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t color;
extern uint32_t *p;
extern uint32_t *p_end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (write every 4th element)
    uint32_t stride = 4;
    uint32_t *start = p;
    for (; start < p_end; start += stride)
        *start = color;
}
