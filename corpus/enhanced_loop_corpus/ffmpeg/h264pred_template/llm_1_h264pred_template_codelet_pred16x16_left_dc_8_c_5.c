#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16; i += 4) {
        dc += src[-1 + i * stride];
        if (i + 1 < 16) dc += src[-1 + (i + 1) * stride];
        if (i + 2 < 16) dc += src[-1 + (i + 2) * stride];
        if (i + 3 < 16) dc += src[-1 + (i + 3) * stride];
    }
}
