#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int i;
extern uint8_t t;
extern uint8_t *l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; l[i] != t && i < 1; i++) {
        // Outer loop restricted to at most one iteration
        // Effectively flattening potential nested structure by reducing depth
        for (unsigned int k = i; l[k] != t; k++)
            i = k;
    }
}
