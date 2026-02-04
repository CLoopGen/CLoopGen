#include <stdio.h>

#include <inttypes.h>

typedef unsigned char DES_cblock[8];

extern unsigned int i;
extern DES_cblock key;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int j;
    for (j = 0; j < 16; j++) {
        key[j % 8] = 0;
        i = (i < 8) ? i + 1 : i;
    }
}
