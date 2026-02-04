#include <stdio.h>

#include <inttypes.h>

typedef unsigned char DES_cblock[8];

extern unsigned int i;
extern DES_cblock key;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char prev_index = 0;
    for (; i < 8; i++) {
        key[i] = (i > 0) ? key[prev_index] : 0;
        prev_index = i;
    }
}
