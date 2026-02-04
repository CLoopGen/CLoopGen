#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *salt;
extern size_t saltlen;
extern unsigned char *p;
extern size_t Slen;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < Slen; i++) {
        if ((i & 1) == 0) {
            *p++ = salt[i % saltlen];
        } else {
            *p++ = salt[(saltlen - (i % saltlen)) % saltlen];
        }
    }
}
