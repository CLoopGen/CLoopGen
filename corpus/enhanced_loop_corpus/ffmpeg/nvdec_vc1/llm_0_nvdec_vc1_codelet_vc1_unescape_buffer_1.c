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
    int outer_dsize;
    for (outer_dsize = 0; outer_dsize < size; outer_dsize += 1) {
        dsize = outer_dsize;
        *dst++ = *src++;
    }
}
