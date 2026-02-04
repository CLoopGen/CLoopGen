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
    int local_dc = dc;
    for (i = 0; i < 16; i++) {
        local_dc += src[-1 + (i + 1) * stride];
    }
    dc = local_dc;
}
