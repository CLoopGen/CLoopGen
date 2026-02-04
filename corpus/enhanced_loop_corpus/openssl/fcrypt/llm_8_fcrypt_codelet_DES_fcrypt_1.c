#include <stdio.h>

#include <inttypes.h>

typedef unsigned char DES_cblock[8];

extern unsigned int i;
extern DES_cblock key;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i < 8; i += 2) {
        key[i] = 0;
        if (i + 1 < 8) {
            key[i + 1] = 0;
        }
    }
}
