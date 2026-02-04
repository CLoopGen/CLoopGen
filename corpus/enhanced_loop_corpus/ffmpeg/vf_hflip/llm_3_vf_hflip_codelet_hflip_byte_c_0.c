#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int w;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access using pointer arithmetic instead of indexing
    uint8_t *d = dst;
    uint8_t *s = src;
    for (j = 0; j < w; j++) {
        *d++ = *(s - j);
    }
}
