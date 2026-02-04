#include <stdio.h>

#include <inttypes.h>

typedef unsigned char DES_cblock[8];

extern  char *str;
extern DES_cblock *key;
extern int i;
extern size_t length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < (int)length; i += 2) {
    register unsigned char j1 = str[i];
    register unsigned char j2 = (i + 1 < (int)length) ? str[i + 1] : 0;
    if ((i % 16) < 8) {
        (*key)[i % 8] ^= (j1 << 1);
        if (i + 1 < (int)length && ((i + 1) % 16) < 8)
            (*key)[(i + 1) % 8] ^= (j2 << 1);
    } else {
        j1 = ((j1 << 4) & 240) | ((j1 >> 4) & 15);
        j1 = ((j1 << 2) & 204) | ((j1 >> 2) & 51);
        j1 = ((j1 << 1) & 170) | ((j1 >> 1) & 85);
        (*key)[7 - (i % 8)] ^= j1;
        if (i + 1 < (int)length && ((i + 1) % 16) >= 8) {
            j2 = ((j2 << 4) & 240) | ((j2 >> 4) & 15);
            j2 = ((j2 << 2) & 204) | ((j2 >> 2) & 51);
            j2 = ((j2 << 1) & 170) | ((j2 >> 1) & 85);
            (*key)[7 - ((i + 1) % 8)] ^= j2;
        }
    }
}
}
