#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *pass;
extern size_t passlen;
extern unsigned char *p;
extern size_t Plen;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t local_passlen = passlen;
    size_t mod_index;
    for (i = 0; i < Plen; i++) {
        mod_index = i - ((i / local_passlen) * local_passlen);
        *p++ = pass[mod_index];
    }
}
