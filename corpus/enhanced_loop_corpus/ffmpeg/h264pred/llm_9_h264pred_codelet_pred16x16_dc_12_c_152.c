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
    for (i = 0; i < 8; i++) {
        dc += src[-1 + i * stride];
        for (j = 0; j < 2; j++) {
            dc += src[-1 + (i * 2 + j + 8) * stride] >> 1;
        }
    }
}
