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
    int limit = 8;
    for (i = 0; i < limit; i++) {
        dc += src[-1 + i * stride] + src[-1 + (i + 8) * stride];
    }
}
