#include <stdio.h>

#include <inttypes.h>

typedef unsigned char DES_cblock[8];

extern  char *str;
extern DES_cblock *key1;
extern DES_cblock *key2;
extern int i;
extern size_t length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < (int)(length / 2); i++) {
    register unsigned char j = str[i];
    int mod32 = i % 32;
    int mod16 = i % 16;
    int mod8 = i % 8;

    if (mod32 < 16) {
        if (mod16 < 8) {
            (*key1)[mod8] ^= (j << 1);
        } else {
            (*key2)[mod8] ^= (j << 1);
        }
    } else {
        j = (j & 15) << 4 | (j & 240) >> 4;
        j = (j & 51) << 2 | (j & 204) >> 2;
        j = (j & 85) << 1 | (j & 170) >> 1;
        if (mod16 < 8) {
            (*key1)[7 - mod8] ^= j;
        } else {
            (*key2)[7 - mod8] ^= j;
        }
    }

    // Additional computational work to increase intensity
    for (int k = 0; k < 3; k++) {
        j ^= (*key1)[k] ^ (*key2)[7 - k];
        j = (j << 1) | (j >> 7);
    }
    (*key1)[i % 8] ^= j;
}
}
