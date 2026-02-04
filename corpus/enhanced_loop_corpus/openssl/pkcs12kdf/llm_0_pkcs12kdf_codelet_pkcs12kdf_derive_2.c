#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *pass;
extern size_t passlen;
extern unsigned char *p;
extern size_t Plen;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t outer;
    for (outer = 0; outer < Plen; outer++) {
        for (i = outer; i < outer + 1; i++)
            *p++ = pass[i % passlen];
    }
}
