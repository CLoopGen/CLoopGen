#include <stdio.h>

#include <inttypes.h>

typedef unsigned char DES_cblock[8];

extern unsigned int i;
extern DES_cblock key;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i < 8; i++) {
        if (i % 2 == 0)
            key[i] = 0;
        else
            continue;
    }
}
