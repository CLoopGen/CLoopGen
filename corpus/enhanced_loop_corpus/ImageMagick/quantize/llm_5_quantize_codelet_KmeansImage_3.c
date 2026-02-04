#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t n;
extern size_t depth;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (depth = 1; n != 0 && depth < 64; depth++)
        if (n & 1)
            n >>= 1;
        else
            n >>= 2;
}
