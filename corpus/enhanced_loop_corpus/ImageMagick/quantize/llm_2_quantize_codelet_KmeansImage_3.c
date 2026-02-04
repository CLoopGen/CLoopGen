#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t n;
extern size_t depth;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    volatile ssize_t* n_ptr = &n;
    for (depth = 1; *n_ptr != 0; depth++) {
        *n_ptr >>= 2;
    }
}
