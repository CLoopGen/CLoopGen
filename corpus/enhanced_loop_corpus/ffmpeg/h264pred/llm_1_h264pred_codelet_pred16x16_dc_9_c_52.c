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
    for (int j = 0; j < 4; j++) {
        for (int k = 0; k < 4; k++) {
            i = j * 4 + k;
            dc += src[-1 + i * stride];
        }
    }
}
