#include <stdio.h>

#include <inttypes.h>

extern int coeff[64];
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = pos; i < 64 * 4; i++) {
        coeff[i % 64] ^= (i >> 3) & 1;
        pos = (i % 64) + 1;
    }
    pos = 64;
}
