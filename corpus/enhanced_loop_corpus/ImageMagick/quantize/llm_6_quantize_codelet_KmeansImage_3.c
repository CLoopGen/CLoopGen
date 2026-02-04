#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t n;
extern size_t depth;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp_depth = 1;
    ssize_t temp_n = n;
    for (depth = 0; temp_n != 0; temp_n >>= 2, depth = temp_depth++)
        ;
    depth = temp_depth;
}
