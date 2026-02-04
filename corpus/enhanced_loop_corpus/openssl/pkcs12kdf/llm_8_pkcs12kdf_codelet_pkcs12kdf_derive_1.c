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
    for (i = 0; i < Slen; i += 2) {
        j = i % saltlen;
        *p++ = salt[j];
        if (i + 1 < Slen)
            *p++ = salt[(j + 1) % saltlen];
    }
}
