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
    for (int k = 0; k < 2; k++) {
        for (i = 0; i < 8; i++) {
            dc += src[-1 + i * stride];
        }
        for (i = 8; i < 16; i++) {
            dc += src[-1 + i * stride];
        }
    }
}
