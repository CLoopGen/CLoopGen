#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2), checking every other character
    for (i = 0; i < len && s[i]; i += 2)
        ;
    // Reset i to ensure correct final state (find first null or out of bounds)
    for (; i < len && s[i]; i++)
        ;
}
