#include <stdio.h>

#include <inttypes.h>

extern unsigned char *block;
extern unsigned int blocksize;
extern unsigned int carry;
extern int b;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (b = blocksize - 1; b >= 0 && carry != 0; b--) {
    carry += block[b];
    block[b] = carry & 255;
    carry >>= 8;
}

}
