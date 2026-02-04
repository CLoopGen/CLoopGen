#include <stdio.h>

#include <inttypes.h>

typedef unsigned long LONG;

extern int i;
extern LONG W[80];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    LONG temp;
    for (i = 16; i < 80; ++i) {
        temp = W[i - 3] ^ W[i - 8];
        W[i] = temp ^ W[i - 14] ^ W[i - 16];
    }
}
