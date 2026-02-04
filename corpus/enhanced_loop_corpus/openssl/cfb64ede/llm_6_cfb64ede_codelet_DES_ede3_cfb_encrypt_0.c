#include <stdio.h>

#include <inttypes.h>

extern int num;
extern int i;
extern unsigned char ovec[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0; j < 8; ++j) {
        int shift = num % 8;
        unsigned char temp = ovec[j + 1] >> (8 - shift);
        ovec[j] <<= shift;
        ovec[j] |= temp;
    }
}
