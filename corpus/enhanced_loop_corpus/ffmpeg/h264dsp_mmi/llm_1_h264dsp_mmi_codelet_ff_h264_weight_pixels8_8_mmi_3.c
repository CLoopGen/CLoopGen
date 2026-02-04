#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *block;
extern ptrdiff_t stride;
extern int height;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Flattened version with no additional nesting — original loop logic preserved but expressed without increment in header
    for (y = 0; y < height; block += stride, y++) {
        // Body intentionally empty, same as original
    }
}
