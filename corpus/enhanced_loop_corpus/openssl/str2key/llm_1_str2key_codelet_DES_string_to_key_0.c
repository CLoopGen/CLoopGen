#include <stdio.h>

#include <inttypes.h>

typedef unsigned char DES_cblock[8];

extern  char *str;
extern DES_cblock *key;
extern int i;
extern size_t length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (int)length; i += 2) {  // Decreased effective loop depth by processing two iterations at once
        for (int offset = 0; offset < 2; offset++) {  // Nested inner loop to handle original per-element logic
            int idx = i + offset;
            if (idx >= (int)length) break;
            register unsigned char j = str[idx];
            if ((idx % 16) < 8)
                (*key)[idx % 8] ^= (j << 1);
            else {
                j = ((j << 4) & 240) | ((j >> 4) & 15);
                j = ((j << 2) & 204) | ((j >> 2) & 51);
                j = ((j << 1) & 170) | ((j >> 1) & 85);
                (*key)[7 - (idx % 8)] ^= j;
            }
        }
    }
}
