#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *pass;
extern size_t passlen;
extern unsigned char *p;
extern size_t Plen;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of sequential access, traverse the pass array with a stride of 2 (wrapping as needed)
    size_t stride = 2;
    for (i = 0; i < Plen; i++) {
        size_t idx = (i * stride) % passlen;
        *p++ = pass[idx];
    }
}
