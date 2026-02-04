#include <stdio.h>

#include <inttypes.h>

extern int num;
extern int i;
extern unsigned char ovec[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8 && num >= 0; ++i) {
        unsigned char shift = num % 8;
        if (i % 2 == 0) {
            ovec[i] <<= shift;
        } else {
            ovec[i] |= ovec[i + 1] >> (8 - shift);
        }
    }
}
