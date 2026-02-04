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
for (i = 0; i < (int)length; i++) {
    register unsigned char j = str[i];
    int mod32 = i % 32;
    int mod16 = i % 16;
    int mod8 = i % 8;

    if (mod32 < 16) {
        if (mod16 < 8)
            (*key1)[mod8] ^= (j << 1);
        else
            (*key2)[mod8] ^= (j << 1);
    } else {
        j = ((j << 4) & 240) | ((j >> 4) & 15);
        j = ((j << 2) & 204) | ((j >> 2) & 51);
        j = ((j << 1) & 170) | ((j >> 1) & 85);
        if (mod16 < 8)
            (*key1)[7 - mod8] ^= j;
        else
            (*key2)[7 - mod8] ^= j;
    }
}
}
