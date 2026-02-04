#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *pass;
extern size_t passlen;
extern unsigned char *p;
extern size_t Plen;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    unsigned char temp;
    for (i = 0; i < Plen; i++) {
        j = i % passlen;
        temp = pass[j];
        *p++ = temp;
    }
}
