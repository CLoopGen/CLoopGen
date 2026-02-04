#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i++) {
        dc += src[i * 2 - stride];
        dc += src[i * 2 + 1 - stride];
        dc += src[i * 2 - stride] * src[i * 2 - stride];
    }
}
