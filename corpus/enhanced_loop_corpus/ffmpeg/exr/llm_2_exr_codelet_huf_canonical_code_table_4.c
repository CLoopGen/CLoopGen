#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t c;
extern uint64_t n[59];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided access (stride of 2) with reverse traversal
    for (i = 58; i > 0; i -= 2) {
        uint64_t nc = ((c + n[i]) >> 1);
        n[i] = c;
        c = nc;
        if (i == 1) break; // Prevent underflow when stepping by 2
        uint64_t nc_prev = ((c + n[i-1]) >> 1);
        n[i-1] = c;
        c = nc_prev;
    }
}
