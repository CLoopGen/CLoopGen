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
    for (i = 0; i < 4; i++) {
        value = ciphertext[i] ^ key[i];
        j = 0;
        if (value != 0) {
            for (; j < 4; j++)
                *p++ = (unsigned char)((value >> (8 * j)) & 255);
        } else {
            *p++ = 0;
            *p++ = 0;
            *p++ = 0;
            *p++ = 0;
        }
    }
}
