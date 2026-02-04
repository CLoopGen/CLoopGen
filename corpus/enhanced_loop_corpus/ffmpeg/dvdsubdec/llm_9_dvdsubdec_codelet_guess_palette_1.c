#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *rgba_palette;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 3; i >= 0; i--) {
        uint32_t val = i * i;
        rgba_palette[i] = val << 8;
    }
}
