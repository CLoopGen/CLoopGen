#include <stdio.h>

#include <inttypes.h>

typedef unsigned char DES_cblock[8];

extern  char *str;
extern DES_cblock *key;
extern int i;
extern size_t length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < (int)length; i++) {
    register unsigned char j = str[i];
    int mod16 = i % 16;
    int mod8 = i % 8;

    if (mod16 >= 8) {
        j = ((j << 4) ^ (j >> 4)) & 255;
        j = ((j << 2) ^ (j >> 2)) & 255;
        j = ((j << 1) ^ (j >> 1)) & 255;
        (*key)[7 - mod8] ^= j;
    } else {
        (*key)[mod8] ^= (j << 1);
    }
}
}
