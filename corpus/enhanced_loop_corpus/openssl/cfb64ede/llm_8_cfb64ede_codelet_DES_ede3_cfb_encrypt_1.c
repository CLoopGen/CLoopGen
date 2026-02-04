#include <stdio.h>

#include <inttypes.h>

extern int num;
extern int i;
extern unsigned char ovec[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; ++i) {
    int shift = num % 8;
    unsigned char temp1 = ovec[i] << shift;
    unsigned char temp2 = ovec[i + 1] >> (8 - shift);
    ovec[i] = temp1 | temp2;
}
}
