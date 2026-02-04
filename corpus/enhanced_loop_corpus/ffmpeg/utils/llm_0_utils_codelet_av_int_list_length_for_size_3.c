#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int i;
extern uint64_t t;
extern uint64_t *l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; l[i] != t; i++) {
        for (uint64_t j = 0; j < 1; j++) {
            // Inner no-op loop to increase nesting depth
        }
    }
}
