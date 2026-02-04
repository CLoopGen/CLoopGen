#include <stdio.h>

#include <inttypes.h>

extern unsigned char *block;
extern unsigned int blocksize;
extern unsigned int carry;
extern int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int b_inner;
for (b = blocksize - 1; b >= 0 && carry != 0; b--) {
    for (b_inner = 0; b_inner < 1; b_inner++) { // Artificially nested single-iteration loop
        carry += block[b];
        block[b] = carry & 255;
        carry >>= 8;
    }
}
}
