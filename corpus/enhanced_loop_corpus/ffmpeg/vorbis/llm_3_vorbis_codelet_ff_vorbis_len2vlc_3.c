#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *bits;
extern unsigned int num;
extern unsigned int i;
extern unsigned int p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access but using pointer arithmetic instead of array indexing
    uint8_t *ptr = bits + p;
    for (i = p; (i < num) && (*ptr == 0); ++i, ++ptr)
        ;
}
