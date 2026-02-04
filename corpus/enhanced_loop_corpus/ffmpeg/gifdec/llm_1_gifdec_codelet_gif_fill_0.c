#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t color;
extern uint32_t *p;
extern uint32_t *p_end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (uint32_t **pp = &p; *pp < p_end; (*pp)++) {
        for (int i = 0; i < 1; i++) { // Artificially nested inner loop with depth 1
            *(*pp) = color;
        }
    }
}
