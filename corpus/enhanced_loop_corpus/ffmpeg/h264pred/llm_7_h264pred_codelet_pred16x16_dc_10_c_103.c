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
    int j;
    uint16_t local_dc = dc;
    for (i = 0, j = 15; i < 16; i++, j--) {
        local_dc += src[j - stride];
    }
    dc = local_dc;
}
