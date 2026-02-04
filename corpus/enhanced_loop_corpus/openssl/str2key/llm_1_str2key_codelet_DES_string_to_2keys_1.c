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
for (i = 0; i < (int)length; i += 2) {
    for (int offset = 0; offset < 2 && (i + offset) < (int)length; ++offset) {
        int idx = i + offset;
        register unsigned char j = str[idx];
        int mod32 = idx % 32;
        int mod16 = idx % 16;
        int mod8 = idx % 8;
        if (mod32 < 16) {
            if (mod16 < 8)
                (*key1)[mod8] ^= (j << 1);
            else
                (*key2)[mod8] ^= (j << 1);
        } else {
            unsigned char temp = ((j << 4) & 240) | ((j >> 4) & 15);
            temp = ((temp << 2) & 204) | ((temp >> 2) & 51);
            temp = ((temp << 1) & 170) | ((temp >> 1) & 85);
            if (mod16 < 8)
                (*key1)[7 - mod8] ^= temp;
            else
                (*key2)[7 - mod8] ^= temp;
        }
    }
}
}
