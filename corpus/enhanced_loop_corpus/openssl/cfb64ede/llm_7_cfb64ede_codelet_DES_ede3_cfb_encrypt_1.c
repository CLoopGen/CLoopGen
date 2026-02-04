#include <stdio.h>

#include <inttypes.h>

extern int num;
extern int i;
extern unsigned char ovec[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int shift = num % 8;
    unsigned char carry = ovec[0];
    for (i = 0; i < 8; ++i) {
        unsigned char next_carry = ovec[i + 1];
        ovec[i] = (ovec[i] << shift) | (next_carry >> (8 - shift));
        if (i > 0) {
            ovec[i - 1] |= (carry >> (8 - shift)); 
        }
        carry = next_carry;
    }
}
