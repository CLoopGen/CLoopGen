#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j = 0;
    for (i = 0; i < len && s[j]; j++, i++) { // Introduce RAW dependency: s[j] where j is incremented alongside i
        if (j >= len) break;
    }
    // Now i and j advance together — loop-carried dependence via j affects memory access s[j]
    // Ensures data dependency between iterations through j used in array indexing
}
