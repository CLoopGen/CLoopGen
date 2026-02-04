#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t color;
extern uint32_t *p;
extern uint32_t *p_end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; p < p_end; p++) {
        *p = color;
        p++; // Skip every other element by incrementing inside the body as well
        if (p >= p_end) break;
    }
}
