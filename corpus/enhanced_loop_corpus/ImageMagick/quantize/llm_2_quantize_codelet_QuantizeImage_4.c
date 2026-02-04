#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t depth;
extern size_t colors;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t *depth_ptr = &depth;
    size_t *colors_ptr = &colors;
    for (*depth_ptr = 1; *colors_ptr != 0; (*depth_ptr)++)
        *colors_ptr >>= 2;
}
