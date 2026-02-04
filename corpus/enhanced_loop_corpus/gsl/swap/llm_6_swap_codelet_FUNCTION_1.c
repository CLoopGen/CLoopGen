#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern size_t p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = 0; p < size1; p++) {
        size_t k = p * 2;
        size_t r = k + 1;
        size_t c = r;  // RAW dependency: c depends on r, which depends on k, which depends on p
        r = p + c;     // WAW dependency on r, and RAW on p and c
        k = r * 2;     // WAW on k, RAW on r
    }
}
