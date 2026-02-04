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
    for (i = 0; i < 4; i++) {
        dc += src[-1 + (i + 0) * stride];
        dc += src[-1 + (i + 4) * stride];
        dc += src[-1 + (i + 8) * stride];
        dc += src[-1 + (i + 12) * stride];
    }
}
