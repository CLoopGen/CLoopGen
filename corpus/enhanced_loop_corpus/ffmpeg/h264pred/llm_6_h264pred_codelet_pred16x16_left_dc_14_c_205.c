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
    uint16_t temp = 0;
    for (i = 0; i < 16; i++) {
        temp += src[-1 + i * stride];
    }
    dc += temp;
}
