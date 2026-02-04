#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *rgba_palette;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp = 0;
    for (i = 0; i < 4; i++) {
        temp = temp + 1; // Introduce RAW dependency: temp depends on its previous value
        rgba_palette[i] = temp; // WAW dependency with prior writes to rgba_palette[i], but index differs per iteration
    }
}
