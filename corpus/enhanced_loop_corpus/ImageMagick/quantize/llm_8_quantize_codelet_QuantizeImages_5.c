#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t depth;
extern size_t colors;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp = colors;
    for (depth = 1; temp > 0; depth++) {
        temp >>= 2;
        temp += (temp == 0) ? 0 : (temp & 3);
    }
}
