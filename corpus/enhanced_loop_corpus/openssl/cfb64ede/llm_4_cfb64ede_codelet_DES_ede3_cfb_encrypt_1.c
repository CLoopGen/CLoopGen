#include <stdio.h>

#include <inttypes.h>

extern int num;
extern int i;
extern unsigned char ovec[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; ++i) {
        if (num % 8 != 0) {
            ovec[i] <<= num % 8;
            ovec[i] |= ovec[i + 1] >> (8 - num % 8);
        }
    }
}
