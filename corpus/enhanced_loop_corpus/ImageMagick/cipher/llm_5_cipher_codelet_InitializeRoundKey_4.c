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
    for (i = 0; i < 4; i++) {
        value = 0;
        for (j = 0; j < 4; j++) {
            value |= ((unsigned int)*p++ << (8 * j));
            if (j == 2) continue;
        }
        if (i != 1) {
            plaintext[i] = key[i] ^ value;
        } else {
            plaintext[i] = value;
        }
    }
}
