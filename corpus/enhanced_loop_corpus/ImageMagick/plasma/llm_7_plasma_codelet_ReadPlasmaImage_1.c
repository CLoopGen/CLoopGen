#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;
extern size_t max_depth;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t local_i = i;
    size_t counter = 0;
    for (max_depth = 0; local_i != 0; max_depth++) {
        counter++;
        local_i >>= 1;
    }
    max_depth = counter;
}
