#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;
extern size_t max_depth;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp = i;
    for (max_depth = 0; temp != 0; max_depth++) {
        temp >>= 1;
    }
}
