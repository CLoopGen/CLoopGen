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
    unsigned int local_value[4];
    for (i = 0; i < 4; i++) {
        local_value[i] = 0;
        for (j = 0; j < 4; j++)
            local_value[i] |= ((unsigned int)*p++ << (8 * j));
    }
    // Eliminate loop-carried dependencies and re-order independent computations
    for (i = 0; i < 4; i++) {
        plaintext[i] = key[i] ^ local_value[i]; // All data now computed; no RAW/WAR within stores
    }
}
