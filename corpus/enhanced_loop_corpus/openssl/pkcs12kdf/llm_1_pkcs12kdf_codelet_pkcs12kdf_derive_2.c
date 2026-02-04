#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *pass;
extern size_t passlen;
extern unsigned char *p;
extern size_t Plen;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (Plen > 0) {
        i = 0;
        for (; i < Plen; ) {
            *p++ = pass[i % passlen];
            i++;
        }
    }
}
