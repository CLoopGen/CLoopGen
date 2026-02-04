#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *salt;
extern size_t saltlen;
extern unsigned char *p;
extern size_t Slen;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (Slen > 0) {
        i = 0;
        for (; i < Slen / 2; i++) {
            *p++ = salt[i % saltlen];
        }
        for (; i < Slen; i++) {
            *p++ = salt[i % saltlen];
        }
    }
}
