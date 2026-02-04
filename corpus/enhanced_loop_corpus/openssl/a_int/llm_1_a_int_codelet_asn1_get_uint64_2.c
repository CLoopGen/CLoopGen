#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *b;
extern size_t blen;
extern size_t i;
extern uint64_t r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (r = 0, i = 0; i < blen; ) {
        for (size_t j = 0; j < 4 && i < blen; j++, i++) {
            r <<= 8;
            r |= b[i];
        }
    }
}
