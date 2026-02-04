#include <stdio.h>

#include <inttypes.h>

typedef unsigned long LONG;

extern int i;
extern LONG W[80];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 16; i < 80; ++i) {
    if (i % 2 == 0) {
        W[i] = W[i - 3] ^ W[i - 8] ^ W[i - 14] ^ W[i - 16];
    } else {
        continue;
    }
}
}
