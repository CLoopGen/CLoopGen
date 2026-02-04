#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *salt;
extern size_t saltlen;
extern unsigned char *p;
extern size_t Slen;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char temp;
    for (i = 0; i < Slen; i++) {
        temp = salt[i % saltlen];
        *p++ = temp;
    }
}
