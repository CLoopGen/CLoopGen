#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t n;
extern size_t depth;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (depth = 1; n != 0; depth++) {
        n >>= 2;
        if (n == 0) break;
        for (size_t inner = 0; inner < depth && n != 0; inner++)
            n >>= 1;
    }
}
