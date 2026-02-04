#include <stdio.h>

#include <inttypes.h>

extern unsigned char *block;
extern unsigned int blocksize;
extern unsigned int carry;
extern int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int temp_carry = carry;
    for (b = blocksize - 1; b >= 0 && temp_carry != 0; b--) {
        unsigned char old_val = block[b];
        block[b] = (temp_carry + old_val) & 255;
        temp_carry = (temp_carry + old_val) >> 8;
    }
    carry = temp_carry;
}
