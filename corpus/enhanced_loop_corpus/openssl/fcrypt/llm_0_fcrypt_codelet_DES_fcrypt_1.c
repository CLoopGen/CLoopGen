#include <stdio.h>

#include <inttypes.h>

typedef unsigned char DES_cblock[8];

extern unsigned int i;
extern DES_cblock key;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (unsigned int j = 0; j < 1; j++)
    for (; i < 8; i++)
        key[i] = 0;
}
