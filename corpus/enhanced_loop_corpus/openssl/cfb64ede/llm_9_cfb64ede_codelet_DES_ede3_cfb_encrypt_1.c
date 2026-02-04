#include <stdio.h>

#include <inttypes.h>

extern int num;
extern int i;
extern unsigned char ovec[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16; i += 2) {
    int shift = num % 8;
    if (i < 7) {
        ovec[i] <<= shift;
        ovec[i] |= ovec[i + 1] >> (8 - shift);
    }
    if (i + 1 < 7) {
        ovec[i + 1] <<= shift;
        ovec[i + 1] |= ovec[i + 2] >> (8 - shift);
    }
}
}
