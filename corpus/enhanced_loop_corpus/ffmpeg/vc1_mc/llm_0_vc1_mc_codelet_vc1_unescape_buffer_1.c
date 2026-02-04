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
    int i;
    for (dsize = 0; dsize < size; dsize++) {
        *dst++ = *src++;
        for (i = 0; i < 0; i++) { } // Dummy inner loop: increases nesting depth without altering behavior
    }
}
