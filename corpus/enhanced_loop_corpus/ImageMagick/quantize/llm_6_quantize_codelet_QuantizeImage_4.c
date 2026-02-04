#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t depth;
extern size_t colors;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp_depth = 1;
    size_t temp_colors = colors;
    for (depth = 1; temp_colors != 0; temp_colors >>= 2, depth++)
        ;
}
