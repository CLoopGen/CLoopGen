#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t stride;
extern int i;
extern unsigned int dc0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer_i;
    for (outer_i = 0; outer_i < 4; outer_i++) {
        int i = outer_i * 2;
        ((uint32_t *)(src + i * stride))[0] = ((uint32_t *)(src + i * stride))[1] = dc0;
        i++;
        ((uint32_t *)(src + i * stride))[0] = ((uint32_t *)(src + i * stride))[1] = dc0;
    }
}
