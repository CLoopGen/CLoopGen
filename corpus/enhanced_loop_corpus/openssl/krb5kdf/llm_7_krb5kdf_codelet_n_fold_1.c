#include <stdio.h>

#include <inttypes.h>

extern unsigned char *block;
extern unsigned int blocksize;
extern unsigned int carry;
extern int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int local_carry[2] = {carry, 0};
    for (b = blocksize - 1; b >= 0; b--) {
        if (local_carry[b & 1] == 0) break;
        unsigned int sum = local_carry[b & 1] + block[b];
        block[b] = sum & 255;
        local_carry[(b - 1) & 1] = sum >> 8;
    }
    carry = local_carry[(blocksize & 1) ^ 1];
}
