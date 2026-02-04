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
        r = c * 2;     // WAW dependency: r is rewritten (write-after-write)
        k = r + p;     // WAR and RAW: uses updated r and current p; creates new dependency on prior r
    }
}
