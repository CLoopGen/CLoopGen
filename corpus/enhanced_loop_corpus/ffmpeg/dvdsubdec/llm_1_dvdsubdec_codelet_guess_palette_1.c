#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *rgba_palette;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 2; i++) {
        rgba_palette[i * 2 + 0] = 0;
        rgba_palette[i * 2 + 1] = 0;
    }
}
