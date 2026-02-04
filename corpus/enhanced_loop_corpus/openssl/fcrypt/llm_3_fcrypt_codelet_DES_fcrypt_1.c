#include <stdio.h>

#include <inttypes.h>

typedef unsigned char DES_cblock[8];

extern unsigned int i;
extern DES_cblock key;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive reverse traversal of the array
    // Iterates from the last element down to the first
    for (i = 7; ~i; i--)
        key[i] = 0;
}
