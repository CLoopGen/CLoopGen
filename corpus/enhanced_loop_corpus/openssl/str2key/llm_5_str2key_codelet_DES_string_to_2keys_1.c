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
    int index_key1, index_key2;

    // Eliminate nested conditionals via direct computation of indices and flags
    int is_first_half = (mod32 < 16);
    int is_lower_quarter = (mod16 < 8);

    index_key1 = is_lower_quarter ? mod8 : (is_first_half ? -1 : 7 - mod8);
    index_key2 = is_lower_quarter ? -1 : (is_first_half ? mod8 : 7 - mod8);

    if (!is_first_half) {
        j = ((j << 4) & 240) | ((j >> 4) & 15);
        j = ((j << 2) & 204) | ((j >> 2) & 51);
        j = ((j << 1) & 170) | ((j >> 1) & 85);
    }

    if (index_key1 >= 0)
        (*key1)[index_key1] ^= j;
    if (index_key2 >= 0)
        (*key2)[index_key2] ^= j;
}
}
