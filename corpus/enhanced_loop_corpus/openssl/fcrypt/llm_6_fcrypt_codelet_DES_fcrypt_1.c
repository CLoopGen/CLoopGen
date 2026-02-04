#include <stdio.h>

#include <inttypes.h>

typedef unsigned char DES_cblock[8];

extern unsigned int i;
extern DES_cblock key;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char temp = 0;
    for (; i < 8; i++) {
        temp = key[i] + temp;
        key[i] = 0;
    }
}
