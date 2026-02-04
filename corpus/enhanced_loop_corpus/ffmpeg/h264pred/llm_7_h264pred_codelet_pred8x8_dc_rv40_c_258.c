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
    uint32_t prev = dc0;
    for (i = 4; i < 8; i++) {
        uint32_t current = prev + 0x100;  // Introduce loop-carried WAW dependency via 'prev'
        ((uint32_t *)(src + i * stride))[0] = current;
        ((uint32_t *)(src + i * stride))[1] = current;
        prev = current;  // Create loop-carried dependency (WAW or flow dependency on 'prev')
    }
}
