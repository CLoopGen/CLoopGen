#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned int *key;
extern unsigned int *plaintext;
extern  unsigned char *p;
extern unsigned int i;
extern unsigned int j;
extern unsigned int value;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 2; i++) {
    value = 0;
    for (j = 0; j < 8; j++) {
        value |= ((unsigned int)*p++ << (4 * j));
    }
    plaintext[i*2] = key[i*2] ^ value;
    plaintext[i*2 + 1] = key[i*2 + 1] ^ (value >> 16);
}
}
