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
        size_t c = r; // RAW dependency: r is read after write in same iteration
        k = c + p;   // WAW and WAR: k is rewritten, creating write-after-write; c and p are used after prior definitions
    }
}
