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
    if ((i % 16) < 8)
        (*key)[i % 8] ^= (j << 1);
    else {
        j = ((j << 4) & 240) | ((j >> 4) & 15);
        j = ((j << 2) & 204) | ((j >> 2) & 51);
        j = ((j << 1) & 170) | ((j >> 1) & 85);
        (*key)[7 - (i % 8)] ^= j;
    }
}

}
