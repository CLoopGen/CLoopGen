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
    dsize = 0;
    for (; dsize < size; dsize++) {
        if (dsize % 2 == 0) {
            *dst++ = *src++;
        } else {
            *dst++ = *(src++) ^ 0xFF; // Invert bits on odd indices
        }
    }
}
