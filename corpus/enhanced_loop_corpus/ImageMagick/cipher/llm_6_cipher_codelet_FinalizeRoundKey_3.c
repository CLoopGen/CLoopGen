#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned int *ciphertext;
extern  unsigned int *key;
extern unsigned char *p;
extern unsigned int i;
extern unsigned int j;
extern unsigned int value;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int temp[4];
    for (i = 0; i < 4; i++) {
        temp[i] = ciphertext[i] ^ key[i];
    }
    for (i = 0; i < 4; i++) {
        value = temp[i];
        for (j = 0; j < 4; j++)
            *p++ = (unsigned char)((value >> (8 * j)) & 255);
    }
}
