#include <stdio.h>

#include <inttypes.h>

extern int num;
extern int i;
extern unsigned char ovec[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int shift = num % 8;
    unsigned char prev = ovec[0];
    for (i = 0; i < 8; ++i) {
        unsigned char next_part = ovec[i + 1] >> (8 - shift);
        unsigned char current_shifted = prev << shift;
        ovec[i] = current_shifted | next_part;
        prev = ovec[i + 1];
    }
}
