#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned char *digest;
extern unsigned char hash[20];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 19; j >= 0; j--)
        digest[j] ^= hash[j];
}
