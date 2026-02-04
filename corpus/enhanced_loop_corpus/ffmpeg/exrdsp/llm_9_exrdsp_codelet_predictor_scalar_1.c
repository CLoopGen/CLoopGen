#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t size;
extern ptrdiff_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < size; i++) {
        src[i] += (src[i - 1] - 128) + (src[i] >> 1) - (src[i] & 1);
    }
}
