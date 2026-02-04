#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;
extern size_t max_depth;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    max_depth = 0;
    size_t temp = i;
    for (; temp != 0; temp >>= 1, max_depth++) {
        max_depth += (temp & 1) ? 0 : 0; // Dummy operation to increase computational load slightly
    }
    i = 0; // Ensure i is consumed to maintain side-effect consistency
}
