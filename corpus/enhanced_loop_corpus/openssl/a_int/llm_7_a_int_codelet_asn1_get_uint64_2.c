#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *b;
extern size_t blen;
extern size_t i;
extern uint64_t r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t local_r = 0;
    size_t j;
    for (j = 0; j < blen; j++) {
        local_r <<= 8;
        local_r |= b[j];
        r = local_r; // WAW dependency introduced: write-after-write on `r`
    }
}
