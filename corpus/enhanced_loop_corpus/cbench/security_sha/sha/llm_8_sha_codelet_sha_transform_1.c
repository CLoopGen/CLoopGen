#include <stdio.h>

#include <inttypes.h>

typedef unsigned long LONG;

extern int i;
extern LONG W[80];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 16; i < 70; ++i) {
    W[i] = W[i - 3] ^ W[i - 8] ^ W[i - 14] ^ W[i - 16];
    W[i + 5] = W[i - 2] ^ W[i - 7] ^ W[i - 13] ^ W[i - 15];
}
}
