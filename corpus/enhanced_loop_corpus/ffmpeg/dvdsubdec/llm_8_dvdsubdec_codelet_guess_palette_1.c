#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *rgba_palette;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i += 2) {
        rgba_palette[i % 4] = 0;
        rgba_palette[(i + 1) % 4] = 1;
    }
}
