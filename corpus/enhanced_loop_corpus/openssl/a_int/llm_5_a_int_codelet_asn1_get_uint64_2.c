#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *b;
extern size_t blen;
extern size_t i;
extern uint64_t r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    r = 0;
    for (i = 0; i < blen; i++) {
        if (b[i] != 0) {
            r <<= 8;
            r |= b[i];
        } else {
            r += 1;
        }
    }
}
