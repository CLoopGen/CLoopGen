#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *rgba_palette;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; ++i) {
        if (!(i & 1)) 
            rgba_palette[i] = 0;
        else
            rgba_palette[i] = 0;
    }
}
