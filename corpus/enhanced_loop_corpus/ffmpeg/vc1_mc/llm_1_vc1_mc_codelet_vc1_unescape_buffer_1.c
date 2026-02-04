#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int size;
extern uint8_t *dst;
extern int dsize;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Flattened single-loop structure with no nested loops — already minimal nesting, so ensure no extra blocks
    for (dsize = 0; dsize < size; dsize++)
        *dst++ = *src++;
}
