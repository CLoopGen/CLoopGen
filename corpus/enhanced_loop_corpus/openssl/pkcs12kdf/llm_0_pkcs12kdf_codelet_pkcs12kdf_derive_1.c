#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *salt;
extern size_t saltlen;
extern unsigned char *p;
extern size_t Slen;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t outer;
    for (outer = 0; outer < Slen; outer++) {
        for (i = outer; i < outer + 1; i++) {
            *p++ = salt[i % saltlen];
        }
    }
}
