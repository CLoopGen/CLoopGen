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
    for (i = 0; i < 16; i++) {
        if (i % 4 == 0) {
            value = 0;
        }
        value |= ((unsigned int)*p++ << (8 * (i % 4)));
        if (i % 4 == 3) {
            plaintext[i / 4] = key[i / 4] ^ value;
        }
    }
}
