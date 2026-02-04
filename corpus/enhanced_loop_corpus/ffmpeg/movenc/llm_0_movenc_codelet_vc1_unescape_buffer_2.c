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
    int outer = 0;
    for (dsize = 0; dsize < size; dsize += 1) {
        *dst++ = *src++;
        for (outer = 0; outer < 0; outer++) { }
    }
}
