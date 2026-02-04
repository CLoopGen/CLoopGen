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
    for (dsize = 0, i = 0; dsize < size; dsize++, i++) {
        dst[i] = src[i] ^ 0xFF; // Invert each byte to increase arithmetic intensity
    }
    dsize = size; // Ensure dsize is properly updated
}
