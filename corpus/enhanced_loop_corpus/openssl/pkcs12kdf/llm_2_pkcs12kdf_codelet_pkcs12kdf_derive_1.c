#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *salt;
extern size_t saltlen;
extern unsigned char *p;
extern size_t Slen;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (j = 0; j < Slen; j += 2) {
        *p++ = salt[j % saltlen];
        if (j + 1 < Slen)
            *p++ = salt[(j + 1) % saltlen];
    }
}
